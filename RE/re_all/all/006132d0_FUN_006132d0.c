
undefined4 * __thiscall FUN_006132d0(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 2;
  *param_1 = &PTR_LAB_00803f60;
  do {
    FUN_0061fdc0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *param_1 = &PTR_FUN_00804394;
  *(undefined1 *)((int)param_1 + 0x99) = 0;
  *(undefined1 *)((int)param_1 + 0x9a) = 1;
  *(bool *)(param_1 + 0x26) = param_2 == 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1f] = 0;
  param_1[0x1b] = 1;
  param_1[0x1c] = 0;
  param_1[0x1d] = 10;
  param_1[0x1e] = 1;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  if (param_2 == 0) {
    iVar1 = FUN_00646b30(0x4c,0x10);
    if (iVar1 == 0) {
      param_2 = 0;
    }
    else {
      param_2 = FUN_00614f00();
    }
  }
  param_1[0x18] = param_2;
  param_1[0x25] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  return param_1;
}

