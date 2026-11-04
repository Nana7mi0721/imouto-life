
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __SEH_epilog replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _fread
   
   Library: Visual Studio 2003 Release */

size_t __cdecl _fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)

{
  size_t sVar1;
  
  __lock_file(_File);
  sVar1 = __fread_lk(_DstBuf,_ElementSize,_Count,_File);
  FUN_004fc4a6();
  return sVar1;
}

