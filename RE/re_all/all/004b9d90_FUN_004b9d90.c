
void __thiscall
FUN_004b9d90(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int local_10;
  int local_c;
  
  *(undefined4 *)(param_1 + 0xec) = param_2;
  *(undefined4 *)(param_1 + 0xf0) = param_3;
  *(undefined4 *)(param_1 + 0xf4) = param_4;
  if (param_5 < 1) {
    local_c = 1;
  }
  else {
    local_c = param_5;
  }
  *(int *)(param_1 + 0xf8) = local_c;
  if (param_5 < 1) {
    local_10 = 1;
  }
  else {
    local_10 = param_5;
  }
  *(int *)(param_1 + 0xfc) = local_10 << 1;
  return;
}

