
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00485cb0(int param_1)

{
  if ((*(char *)(param_1 + 0xac) != '\0') || (*(char *)(param_1 + 0xad) != '\0')) {
    *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(param_1 + 0x4c);
  }
  *(undefined8 *)(param_1 + 0x140) = _DAT_007d0a60;
  *(undefined4 *)(param_1 + 0x74) = 0;
  return;
}

