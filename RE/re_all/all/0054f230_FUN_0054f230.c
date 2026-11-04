
uint FUN_0054f230(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,
                 undefined4 param_9,int param_10,undefined4 param_11)

{
  int iVar1;
  undefined1 local_c00 [3072];
  
  iVar1 = FUN_0054ee60(param_1,param_2,param_3,param_4,param_5,0,param_11,param_9,0,0);
  if (iVar1 == -1) {
    return 0xffffffff;
  }
  if (param_10 != 0) {
    if (param_8 == 0) {
      FUN_00541020(param_2,local_c00);
      iVar1 = FUN_0054ee60(param_1,local_c00,0,0,0,0,param_11,param_10,0,0);
      return (uint)(iVar1 == -1);
    }
    if (param_8 == 1) {
      iVar1 = FUN_0054ee60(param_1,0,param_6,param_7,1,0,param_11,param_10,0,0);
      return (uint)(iVar1 == -1);
    }
  }
  return 1;
}

