
void __fastcall FUN_00613390(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_00804394;
  if (*(char *)(param_1 + 0x26) != '\0') {
    (*(code *)**(undefined4 **)param_1[0x18])(0);
    FUN_00646b80(param_1[0x18]);
  }
  iVar1 = 2;
  do {
    FUN_0061fdf0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *param_1 = &PTR_LAB_00803f60;
  return;
}

