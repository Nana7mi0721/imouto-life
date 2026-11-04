
void __fastcall FUN_004da170(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    FUN_004da140(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
    deallocate(*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4) >> 5);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}

