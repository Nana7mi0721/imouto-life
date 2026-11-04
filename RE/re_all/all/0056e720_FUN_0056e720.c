
void FUN_0056e720(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 uint param_5,uint param_6)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = CONCAT44(param_6,param_5);
  if ((param_5 & param_6) == 0xffffffff) {
    uVar2 = FUN_0052dc10();
  }
  FUN_0052dcb0(param_1,param_2,1);
  iVar1 = thunk_FUN_005954e0();
  while (iVar1 == 0) {
    FUN_0056da20(1);
    iVar1 = thunk_FUN_005954e0();
  }
  FUN_0056e590(param_2,param_3,uVar2,param_4);
  return;
}

