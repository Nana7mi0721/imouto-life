
undefined4 __fastcall FUN_0055c6b0(undefined4 param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar3 = FUN_0057e0e0(param_1);
  if (iVar3 == 0) {
    return 0xffffffff;
  }
  FUN_0056da60(&DAT_00a83a30,"..\\..\\..\\..\\Source\\Library\\Main\\DxSound.cpp",0xb3f);
  do {
    iVar3 = DAT_00a83a1c;
    while( true ) {
      if (*(int *)(iVar3 + 0xc) == 0) {
        FUN_0056dac0(&DAT_00a83a30);
        return 0;
      }
      iVar1 = *(int *)(iVar3 + 4);
      iVar6 = 0;
      bVar2 = false;
      if (*(int *)(iVar1 + 0x70) < 1) break;
      piVar5 = (int *)(iVar1 + 0xc4);
      do {
        if ((*piVar5 != 0) && (DAT_00a83c64 == 0)) {
          iVar4 = FUN_0057ee90(piVar5);
          if (iVar4 == 0) {
            bVar2 = true;
          }
        }
        iVar6 = iVar6 + 1;
        piVar5 = piVar5 + 0x6e;
      } while (iVar6 < *(int *)(iVar1 + 0x70));
      if (!bVar2) break;
      iVar3 = *(int *)(iVar3 + 0xc);
    }
    *(undefined4 *)(iVar1 + 0x44) = 0;
    FUN_00580810(iVar1 + 0x48);
  } while( true );
}

