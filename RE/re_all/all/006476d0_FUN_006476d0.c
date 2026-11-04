
undefined4 FUN_006476d0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((code *)param_1[0xc] == (code *)0x0) {
    uVar1 = FUN_006507b0(*param_1,s_No__get__routine_setup_00a0653c);
    FUN_006512e0(*(undefined4 *)(*param_1 + 0x274),uVar1);
    return 0;
  }
  if (param_1[0xd] == 0) {
    uVar1 = FUN_006507b0(*param_1,s_No__put__routine_setupl__probabl_00a064fc);
    FUN_006512e0(*(undefined4 *)(*param_1 + 0x274),uVar1);
    return 0;
  }
  uVar1 = (*(code *)param_1[0xc])(param_1,param_2,param_3,param_4);
  return uVar1;
}

