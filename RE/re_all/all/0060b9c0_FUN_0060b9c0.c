
undefined4 * __thiscall FUN_0060b9c0(undefined4 *param_1,byte param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_FUN_00803ef0;
  if (param_1[0x1b] != 0) {
    (*(code *)**(undefined4 **)param_1[0x1c])(0);
    FUN_00646b80(param_1[0x1c]);
    (*(code *)**(undefined4 **)param_1[0x1b])(0);
    FUN_00646b80(param_1[0x1b]);
  }
  puVar2 = param_1 + 0x16;
  iVar1 = 3;
  do {
    FUN_00646b80(*puVar2);
    puVar2 = puVar2 + -1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00646b80(param_1[0xf]);
  if (*(char *)(param_1 + 0x19) != '\0') {
    (*(code *)**(undefined4 **)param_1[0x17])(0);
    FUN_00646b80(param_1[0x17]);
  }
  *param_1 = &PTR_LAB_00803f60;
  if ((param_2 & 1) != 0) {
    FUN_00646b80(param_1);
  }
  return param_1;
}

