
undefined4
FUN_0051d2c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  
  iVar3 = DAT_00a381a0;
  iVar4 = DAT_00a38198;
  uVar1 = DAT_00a381a0 * 10;
  if (DAT_00a37f84 < uVar1) {
    DAT_00a37f78 = FUN_0056e1b0(DAT_00a37f78,uVar1,
                                "..\\..\\..\\..\\Source\\Library\\Main\\DxGraphics.cpp",0x81c7);
    if (DAT_00a37f78 == 0) {
      return 0xffffffff;
    }
    DAT_00a37f84 = uVar1;
  }
  iVar2 = DAT_00a37f78;
  FUN_0056d380(DAT_00a37f78,0,uVar1);
  FUN_0051a320(param_1,param_2,param_3,param_5,iVar2);
  if (iVar4 < iVar3) {
    psVar5 = (short *)(iVar2 + 4 + iVar4 * 10);
    do {
      if (psVar5[2] != 0) {
        if (((psVar5[2] & 0xcU) == 0) || (psVar5[1] <= *psVar5)) {
          FUN_00761d30(DAT_00a37e58,(int)psVar5[-2],iVar4,psVar5[-1] + 1,iVar4,param_4);
        }
        else {
          FUN_00761d30(DAT_00a37e58,(int)psVar5[-2],iVar4,*psVar5 + 1,iVar4,param_4);
          FUN_00761d30(DAT_00a37e58,(int)psVar5[1],iVar4,psVar5[-1] + 1,iVar4,param_4);
        }
      }
      iVar4 = iVar4 + 1;
      psVar5 = psVar5 + 5;
    } while (iVar4 < iVar3);
  }
  return 0;
}

