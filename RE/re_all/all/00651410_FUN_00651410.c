
undefined4 FUN_00651410(undefined4 *param_1,uint param_2,uint param_3,uint param_4,ushort param_5)

{
  if ((uint)param_1[0xe] <= param_2) {
    FUN_006512e0(param_1[0x9d],*param_1,s__lu__Col_out_of_range__max__lu_00a06c48,param_2,
                 param_1[0xe] - 1);
    return 0;
  }
  if ((uint)param_1[0xf] <= param_3) {
    FUN_006512e0(param_1[0x9d],*param_1,s__lu__Row_out_of_range__max__lu_00a06c28,param_3,
                 param_1[0xf] - 1);
    return 0;
  }
  if ((uint)param_1[0x10] <= param_4) {
    FUN_006512e0(param_1[0x9d],*param_1,s__lu__Depth_out_of_range__max__lu_00a06c04,param_4,
                 param_1[0x10] - 1);
    return 0;
  }
  if (*(short *)((int)param_1 + 0x7e) == 2) {
    if (*(ushort *)((int)param_1 + 0x62) <= param_5) {
      FUN_006512e0(param_1[0x9d],*param_1,s__lu__Sample_out_of_range__max__l_00a06be0,param_5,
                   *(ushort *)((int)param_1 + 0x62) - 1);
      return 0;
    }
  }
  return 1;
}

