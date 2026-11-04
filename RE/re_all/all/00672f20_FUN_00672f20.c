
byte FUN_00672f20(int param_1,byte param_2)

{
  byte bVar1;
  
  param_2 = param_2 & 0xb;
  if (param_2 == 0) {
    if ((*(uint *)(param_1 + 0x74) & 0x8000) == 0) {
      FUN_006689d0(param_1,s_png_set_unknown_chunks_now_expec_00a0cd10);
      param_2 = *(byte *)(param_1 + 0x74) & 0xb;
      if ((*(byte *)(param_1 + 0x74) & 0xb) != 0) goto LAB_00672f5b;
    }
    FUN_00668620(param_1,s_invalid_location_in_png_set_unkn_00a0cce4);
  }
LAB_00672f5b:
  bVar1 = -param_2 & param_2;
  if (param_2 != bVar1) {
    do {
      param_2 = param_2 & ~bVar1;
      bVar1 = -param_2 & param_2;
    } while (param_2 != bVar1);
  }
  return param_2;
}

