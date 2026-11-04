
int FUN_006be910(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int local_8;
  int local_4;
  
  iVar7 = 0;
  uVar9 = 0;
  local_4 = 0;
  iVar8 = 0;
  local_8 = 0;
  iVar2 = FUN_006bf110(param_1);
  iVar3 = FUN_006bf140(param_1);
  do {
    if (iVar3 < 0) {
      return -0x14;
    }
    if (iVar2 == 0) {
      iVar7 = iVar7 + 1;
      local_8 = iVar7;
      if (0x20 < iVar7) {
        return -0x14;
      }
    }
    else {
      local_4 = local_4 + 1;
      if (0x20 < local_4) {
        return -0x14;
      }
      iVar2 = FUN_006bf0c0(param_1,5);
      bVar1 = (&DAT_00832460)[iVar2];
      cVar6 = (&DAT_00832440)[iVar2];
      iVar2 = 1 << (bVar1 & 0x1f);
      if (0 < iVar2) {
        pcVar5 = (char *)(param_2 + iVar8 * 2);
        iVar8 = iVar8 + iVar2;
        do {
          *pcVar5 = cVar6;
          pcVar5[1] = bVar1 + (char)local_8;
          cVar6 = cVar6 + '\x01';
          pcVar5 = pcVar5 + 2;
          iVar2 = iVar2 + -1;
          iVar7 = local_8;
        } while (iVar2 != 0);
      }
      uVar4 = 0x80000000 >> ((char)iVar7 - 1U & 0x1f);
      while( true ) {
        if (iVar7 < 1) {
          return iVar8;
        }
        if ((uVar9 & uVar4) == 0) break;
        uVar9 = uVar9 ^ uVar4;
        uVar4 = uVar4 << 1;
        iVar7 = iVar7 + -1;
        local_8 = iVar7;
      }
      if (iVar7 < 1) {
        return iVar8;
      }
      uVar9 = uVar9 | uVar4;
    }
    iVar2 = FUN_006bf110(param_1);
    iVar3 = FUN_006bf140(param_1);
  } while( true );
}

