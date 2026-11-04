
undefined4 FUN_0056c180(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((DAT_00ab012c != 0) || (iVar2 = FUN_0056c020(), -1 < iVar2)) {
    local_c = DAT_00aba0c0 - DAT_00aba0b8;
    local_10 = DAT_00aba0b8;
    local_18 = DAT_00aba0c4 - DAT_00aba0bc;
    if ((local_c == 0) || (iVar2 = DAT_00aba0bc, local_18 == 0)) {
      local_10 = 0;
      iVar2 = 0;
      FUN_005167a0(&local_c,&local_18);
    }
    FUN_0056c0e0();
    if ((DAT_00ab0130 < 1) || (iVar3 = FUN_00536eb0(DAT_00ab0130), iVar3 < 0)) {
      DAT_00ab0130 = 0;
      local_14 = DAT_00ab0134;
      iVar3 = DAT_00aba0a8;
    }
    else {
      local_14 = DAT_00ab0130;
    }
    iVar4 = local_18 / iVar3;
    if (0x4f < iVar4) {
      iVar4 = 0x50;
    }
    local_4 = FUN_00543f70(0xff,0xff,0xff);
    local_8 = FUN_00543f70(0,0,0);
    if (0 < iVar4) {
      psVar6 = &DAT_00ab0144;
      do {
        iVar5 = 0;
        sVar1 = *psVar6;
        while (sVar1 != 0) {
          iVar5 = iVar5 + 1;
          sVar1 = psVar6[iVar5];
        }
        FUN_0053f880(local_10,iVar2,psVar6,iVar5,local_4,local_14,local_8,0);
        psVar6 = psVar6 + 0xff;
        iVar2 = iVar2 + iVar3;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  return 0;
}

