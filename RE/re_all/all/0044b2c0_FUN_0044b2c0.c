
void __thiscall
FUN_0044b2c0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int local_14;
  int local_10;
  int local_c;
  
  if (*(int *)(param_1 + 0x1904) < 1) {
    local_c = 1;
  }
  else {
    local_c = *(int *)(param_1 + 0x1904);
  }
  *(int *)(param_1 + 0x1900) =
       *(int *)(param_1 + 0x18fc) -
       ((*(int *)(param_1 + 0x18fc) - *(int *)(param_1 + 0x1900)) * *(int *)(param_1 + 0x1908)) /
       local_c;
  if (*(int *)(param_1 + 0x1900) == 100) {
    *(undefined4 *)(param_1 + 0x18f0) = param_2;
    *(undefined4 *)(param_1 + 0x18f8) = param_3;
  }
  else {
    if (*(int *)(param_1 + 0x1904) < 1) {
      local_10 = 1;
    }
    else {
      local_10 = *(int *)(param_1 + 0x1904);
    }
    *(int *)(param_1 + 0x18f0) =
         *(int *)(param_1 + 0x18ec) -
         ((*(int *)(param_1 + 0x18ec) - *(int *)(param_1 + 0x18f0)) * *(int *)(param_1 + 0x1908)) /
         local_10;
    if (*(int *)(param_1 + 0x1904) < 1) {
      local_14 = 1;
    }
    else {
      local_14 = *(int *)(param_1 + 0x1904);
    }
    *(int *)(param_1 + 0x18f8) =
         *(int *)(param_1 + 0x18f4) -
         ((*(int *)(param_1 + 0x18f4) - *(int *)(param_1 + 0x18f8)) * *(int *)(param_1 + 0x1908)) /
         local_14;
  }
  *(undefined4 *)(param_1 + 0x18ec) = param_2;
  *(undefined4 *)(param_1 + 0x18f4) = param_3;
  *(undefined4 *)(param_1 + 0x18fc) = param_4;
  *(undefined4 *)(param_1 + 0x1908) = param_5;
  *(undefined4 *)(param_1 + 0x1904) = param_5;
  return;
}

