
undefined4 FUN_005966b0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  
  if (*param_4 == 0) {
    if ((param_4[5] != 0) && (iVar1 = FUN_0056d130(param_1 + 0x5c,param_4[5]), iVar1 == 0)) {
      param_4[4] = 1;
    }
  }
  else {
    psVar4 = (short *)(param_1 + 0x5c);
    if (*psVar4 != 0x40) {
      iVar1 = 0;
      if (0 < param_4[1]) {
        iVar3 = 0;
        do {
          iVar2 = FUN_0056d130(psVar4,*param_4 + iVar3);
          if (iVar2 == 0) {
            return 1;
          }
          iVar1 = iVar1 + 1;
          iVar3 = iVar3 + 0x80;
        } while (iVar1 < param_4[1]);
      }
      FUN_0056cf70(param_4[1] * 0x80 + *param_4,0x80,psVar4);
      param_4[1] = param_4[1] + 1;
      if ((param_4[2] != 0) && (param_4[2] == param_4[1])) {
        return 0;
      }
    }
  }
  return 1;
}

