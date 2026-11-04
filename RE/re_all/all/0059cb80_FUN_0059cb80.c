
undefined4
FUN_0059cb80(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar3 = param_1;
  iVar1 = param_3 + param_2 * 4;
  iVar2 = iVar1 * 0x140c + 0x14 + param_1;
  if (param_7 != 0) {
    FUN_0059be30(iVar2,1,param_4,param_6);
  }
  FUN_0056d420(*(int *)(iVar2 + 0x408) * param_4 + 0x40c + iVar2,param_5,
               *(int *)(iVar2 + 0x408) * param_6);
  iVar2 = param_2 * 0x100 + 0x2717c + param_1;
  iVar1 = iVar1 * 0x100 + 0x1e134 + param_1;
  if (param_4 < param_4 + param_6) {
    pbVar4 = (byte *)(iVar2 + param_4);
    param_1 = (param_4 + param_6) - param_4;
    do {
      pbVar4[iVar1 - iVar2] = 1;
      if ((*(int *)(iVar3 + param_3 * 4) != 0) &&
         ((*pbVar4 == 0xff || ((int)(uint)*pbVar4 <= param_3)))) {
        *pbVar4 = (byte)param_3;
      }
      pbVar4 = pbVar4 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  if (*(int *)(iVar3 + param_3 * 4) != 0) {
    FUN_0059c860(iVar3,param_2,param_4);
  }
  return 0;
}

