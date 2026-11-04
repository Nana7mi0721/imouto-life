
void FUN_00669850(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if ((param_3 < 0x10) || (625000000 < param_3)) {
    *(ushort *)((int)param_2 + 0x4a) = *(ushort *)((int)param_2 + 0x4a) | 0x8000;
    FUN_00668bc0(param_1,s_gamma_value_out_of_range_00a0bdd8,1);
  }
  else {
    if (((*(uint *)(param_1 + 0x74) & 0x8000) != 0) && ((*(byte *)((int)param_2 + 0x4a) & 8) != 0))
    {
      *(ushort *)((int)param_2 + 0x4a) = *(ushort *)((int)param_2 + 0x4a) | 0x8000;
      FUN_00668bc0(param_1,s_duplicate_00a0bdf4,1);
      return;
    }
    if ((*(ushort *)((int)param_2 + 0x4a) & 0x8000) == 0) {
      iVar1 = FUN_006698d0(param_1,param_2,param_3,1);
      if (iVar1 != 0) {
        *(byte *)((int)param_2 + 0x4a) = *(byte *)((int)param_2 + 0x4a) | 9;
        *param_2 = param_3;
        return;
      }
    }
  }
  return;
}

