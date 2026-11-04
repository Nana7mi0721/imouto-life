
undefined4 FUN_006558d0(int param_1,uint param_2,int param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  longlong lVar2;
  
  if ((*(uint *)(param_1 + 0xc) & 0x800) == 0) {
    lVar2 = (**(code **)(param_1 + 0x280))(*(undefined4 *)(param_1 + 0x274),param_2,param_3,0);
    if ((lVar2 == CONCAT44(param_3,param_2)) &&
       (uVar1 = (**(code **)(param_1 + 0x278))(*(undefined4 *)(param_1 + 0x274),param_5,param_4),
       uVar1 == param_4)) {
      return 0;
    }
  }
  else {
    uVar1 = param_2 + param_4;
    if ((((param_3 == 0) && (param_2 <= uVar1)) && (uVar1 - param_2 == param_4)) &&
       ((param_4 <= uVar1 && (uVar1 <= *(uint *)(param_1 + 0x268))))) {
      FUN_00650840(param_5,*(int *)(param_1 + 0x264) + param_2,param_4);
      return 0;
    }
  }
  return 3;
}

