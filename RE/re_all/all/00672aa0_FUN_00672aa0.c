
void FUN_00672aa0(int param_1,int param_2,undefined4 *param_3)

{
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != (undefined4 *)0x0)) &&
     ((*(uint *)(param_1 + 0x74) & 0x200) == 0)) {
    if (((((*(byte *)((int)param_3 + 2) != 0) && (*(byte *)((int)param_3 + 2) < 0xd)) &&
         ((*(byte *)((int)param_3 + 3) != 0 &&
          ((*(byte *)((int)param_3 + 3) < 0x20 && (*(byte *)(param_3 + 1) < 0x18)))))) &&
        (*(byte *)((int)param_3 + 5) < 0x3c)) && (*(byte *)((int)param_3 + 6) < 0x3d)) {
      *(undefined4 *)(param_2 + 0x8c) = *param_3;
      *(undefined4 *)(param_2 + 0x90) = param_3[1];
      *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x200;
      return;
    }
    FUN_006687b0(param_1,s_Ignoring_invalid_time_value_00a0bcdc);
  }
  return;
}

