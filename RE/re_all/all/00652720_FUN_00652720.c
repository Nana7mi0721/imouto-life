
uint FUN_00652720(int param_1,uint param_2,ushort param_3)

{
  param_2 = param_2 / *(uint *)(param_1 + 100);
  if (*(short *)(param_1 + 0x7e) == 2) {
    if (*(ushort *)(param_1 + 0x62) <= param_3) {
      FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFComputeStrip",
                   s__lu__Sample_out_of_range__max__l_00a06be0,param_3,*(ushort *)(param_1 + 0x62));
      return 0;
    }
    param_2 = param_2 + *(int *)(param_1 + 0xa4) * (uint)param_3;
  }
  return param_2;
}

