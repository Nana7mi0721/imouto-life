
void FUN_006875b0(int param_1)

{
  undefined4 uVar1;
  
  FUN_00695420(param_1,0);
  if (*(char *)(param_1 + 0xd0) == '\0') {
    FUN_00694960(param_1);
    FUN_00693eb0(param_1);
    FUN_006938e0(param_1,0);
  }
  FUN_006931a0(param_1);
  if (*(char *)(param_1 + 0xd1) == '\0') {
    FUN_006905e0(param_1);
  }
  else {
    FUN_00691f10();
  }
  uVar1 = 1;
  if ((*(int *)(param_1 + 200) < 2) && (*(char *)(param_1 + 0xd2) == '\0')) {
    uVar1 = 0;
  }
  FUN_0068fd20(param_1,uVar1);
  FUN_0068fb80(param_1,0);
  FUN_00686a50(param_1);
  (**(code **)(*(int *)(param_1 + 4) + 0x18))(param_1);
  (*(code *)**(undefined4 **)(param_1 + 0x188))(param_1);
  return;
}

