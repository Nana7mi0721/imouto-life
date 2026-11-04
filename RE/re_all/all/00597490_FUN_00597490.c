
undefined4 FUN_00597490(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_1[4];
  if (param_1[1] == iVar1) {
    param_1[1] = 0;
  }
  if (param_1[2] == iVar1) {
    param_1[2] = 0;
  }
  if (iVar1 < param_1[3] + param_2) {
    iVar2 = *param_1;
    param_2 = (param_1[3] * 3) / 2 + 1000 + param_2;
    param_1[4] = param_2;
    iVar5 = FUN_0056e030(param_2,"..\\..\\..\\..\\Source\\Library\\Main\\DxRingBuffer.cpp",0xa5);
    *param_1 = iVar5;
    if (iVar5 == 0) {
      FUN_0056e1d0(iVar2);
      FUN_0056d380(param_1,0,0x14);
      FUN_0056bca0(&DAT_007d9f58,param_1[4]);
      return 0xffffffff;
    }
    iVar3 = param_1[3];
    if (iVar3 != 0) {
      iVar4 = param_1[1];
      if (iVar1 < iVar3 + iVar4) {
        FUN_0056d420(iVar5,iVar4 + iVar2,iVar1 - iVar4);
        FUN_0056d420((*param_1 - param_1[1]) + iVar1,iVar2,(param_1[3] - iVar1) + param_1[1]);
      }
      else {
        FUN_0056d420(iVar5,iVar4 + iVar2,iVar3);
      }
    }
    param_1[1] = 0;
    param_1[2] = param_1[3];
    FUN_0056e1d0(iVar2);
  }
  return 0;
}

