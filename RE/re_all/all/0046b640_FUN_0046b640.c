
void __fastcall FUN_0046b640(undefined4 param_1)

{
  LPCSTR pCVar1;
  int iVar2;
  DWORD fl;
  PVOID pdv;
  int iVar3;
  
  if (DAT_00a0f82c != 0) {
    FUN_00417950(param_1);
  }
  FUN_00475d30();
  FUN_005157a0(0);
  FUN_00536610();
  FUN_00550c60(0);
  FUN_0052ec70();
  if (*DAT_00a16680 == '\x01') {
    FUN_00401000();
    FUN_00401670();
    FUN_00401080();
  }
  FUN_0042baa0(0,DAT_00a117bc,DAT_00a18a8c);
  Sleep(100);
  pCVar1 = (LPCSTR)FUN_004cbb30();
  SetCurrentDirectoryA(pCVar1);
  iVar3 = 0;
  while( true ) {
    iVar2 = FUN_004cc430();
    if (iVar2 <= iVar3) break;
    pdv = (PVOID)0x0;
    fl = 0x10;
    FUN_004cc4c0(iVar3);
    pCVar1 = (LPCSTR)FUN_004cbb30();
    RemoveFontResourceExA(pCVar1,fl,pdv);
    iVar3 = iVar3 + 1;
  }
  FUN_004b9e50();
                    /* WARNING: Subroutine does not return */
  _exit(0);
}

