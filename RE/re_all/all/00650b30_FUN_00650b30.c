
undefined8
FUN_00650b30(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            undefined4 param_6)

{
  undefined8 uVar1;
  longlong lVar2;
  
  uVar1 = __allmul(param_2,param_3,param_4,param_5);
  if ((param_4 == 0 && param_5 == 0) ||
     (lVar2 = __aulldiv(uVar1,param_4,param_5), lVar2 == CONCAT44(param_3,param_2))) {
    return uVar1;
  }
  FUN_006512e0(*(undefined4 *)(param_1 + 0x274),param_6,s_Integer_overflow_in__s_00a066ac,param_6);
  return 0;
}

