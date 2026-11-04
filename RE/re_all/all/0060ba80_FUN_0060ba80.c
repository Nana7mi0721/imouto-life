
undefined4 * __thiscall FUN_0060ba80(undefined4 *param_1,byte param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_FUN_00803f90;
  if (param_1[0x1d] != 0) {
    (*(code *)**(undefined4 **)param_1[0x1e])(0);
    FUN_00646b80(param_1[0x1e]);
    (*(code *)**(undefined4 **)param_1[0x1d])(0);
    FUN_00646b80(param_1[0x1d]);
  }
  puVar2 = param_1 + 0x18;
  iVar1 = 3;
  do {
    FUN_00646b80(*puVar2);
    puVar2 = puVar2 + -1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00646b80(param_1[0x11]);
  if (*(char *)(param_1 + 0x1b) != '\0') {
    (*(code *)**(undefined4 **)param_1[0x19])(0);
    FUN_00646b80(param_1[0x19]);
  }
  *param_1 = &PTR_LAB_00803f60;
  if ((param_2 & 1) != 0) {
    FUN_00646b80(param_1);
  }
  return param_1;
}

