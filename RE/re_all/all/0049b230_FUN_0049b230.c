
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0049b230(int param_1)

{
  int iVar1;
  double local_3c;
  double local_30;
  double local_24;
  
  FUN_004cb840(param_1 + 0x1c);
  FUN_004ce950();
  FUN_004ce950();
  FUN_004ce950();
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  if (*(char *)(param_1 + 0x98) == '\0') {
    *(undefined8 *)(param_1 + 0x88) = _DAT_007d0a60;
    *(undefined8 *)(param_1 + 0x90) = _DAT_007d0a60;
  }
  else {
    *(undefined8 *)(param_1 + 0x88) = _DAT_007d1090;
  }
  FUN_004cb840(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0xe4) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined1 *)(param_1 + 0xe2) = 0;
  *(undefined1 *)(param_1 + 0xe3) = 0;
  iVar1 = FUN_004cbbc0(&DAT_007d1088,0);
  if (iVar1 != DAT_007d0624) {
    if (((double)(iVar1 + 1) * _DAT_00829888) / (double)DAT_0084b244 <= *(double *)(param_1 + 0x80))
    {
      local_24 = ((double)(iVar1 + 1) * _DAT_00829888) / (double)DAT_0084b244;
    }
    else {
      local_24 = *(double *)(param_1 + 0x80);
    }
    if (_DAT_00802e18 <= local_24) {
      if (((double)(iVar1 + 1) * _DAT_00829888) / (double)DAT_0084b244 <=
          *(double *)(param_1 + 0x80)) {
        local_3c = ((double)(iVar1 + 1) * _DAT_00829888) / (double)DAT_0084b244;
      }
      else {
        local_3c = *(double *)(param_1 + 0x80);
      }
      local_30 = local_3c;
    }
    else {
      local_30 = _DAT_00802e18;
    }
    *(double *)(param_1 + 0x80) = local_30;
  }
  return;
}

