
void __fastcall FUN_004d9e70(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004d9e40(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
    deallocate(*(undefined4 *)(param_1 + 4),
               (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4)) / 0xbec);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

