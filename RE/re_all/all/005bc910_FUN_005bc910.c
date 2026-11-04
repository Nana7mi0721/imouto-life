
undefined4 FUN_005bc910(int param_1,uint param_2,int *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_38 [14];
  
  if (0xe < param_1 + param_2) {
    return 0xffffffff;
  }
  if (param_2 == 1) {
    uVar1 = FUN_005bb8e0(param_1,1,*param_3 + 4);
    return uVar1;
  }
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      local_38[uVar2] = *(undefined4 *)(param_3[uVar2] + 4);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  uVar1 = FUN_005bb8e0(param_1,param_2,local_38);
  return uVar1;
}

