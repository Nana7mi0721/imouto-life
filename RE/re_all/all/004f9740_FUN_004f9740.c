
undefined4 FUN_004f9740(void *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (void *)0x0) {
    uVar1 = 0xffffff9a;
  }
  else {
    if (*(int *)((int)param_1 + 0xe0) != 0) {
      FUN_004fb420(param_1);
    }
    (**(code **)((int)param_1 + 0x14))
              (*(undefined4 *)((int)param_1 + 0x1c),*(undefined4 *)((int)param_1 + 0x30));
    if (param_1 != (void *)0x0) {
      _free(param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}

