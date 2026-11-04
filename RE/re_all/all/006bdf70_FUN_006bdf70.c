
undefined4 FUN_006bdf70(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined1 local_14 [20];
  
  if (param_4 == (undefined4 *)0x0) {
    return 0xffffffec;
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  FUN_006bf010(local_14,*param_4,param_4[1]);
  uVar1 = FUN_006bdfd0(local_14,param_1,param_2,param_3,param_4);
  return uVar1;
}

