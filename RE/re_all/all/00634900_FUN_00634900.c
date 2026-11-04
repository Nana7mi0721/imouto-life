
void __thiscall FUN_00634900(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0xed) == '\0') {
    *(undefined1 *)(param_1 + 0xed) = 0;
    *(undefined4 *)(param_1 + 0xa8) = param_2;
    return;
  }
  FUN_00646b80(*(undefined4 *)(param_1 + 0xa8));
  *(undefined1 *)(param_1 + 0xed) = 0;
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  return;
}

