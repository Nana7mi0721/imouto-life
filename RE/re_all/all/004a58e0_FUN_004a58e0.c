
void __thiscall FUN_004a58e0(int param_1,undefined4 param_2)

{
  int local_c;
  
  *(undefined4 *)(param_1 + 0x250) = param_2;
  *(undefined4 *)(param_1 + 0x254) = param_2;
  *(int *)(param_1 + 600) = (int)*(short *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x254) == 0) {
    local_c = 1;
  }
  else {
    local_c = *(int *)(param_1 + 0x254);
  }
  *(short *)(param_1 + 0x44) =
       (short)((*(int *)(param_1 + 600) * *(int *)(param_1 + 0x250)) / local_c);
  return;
}

