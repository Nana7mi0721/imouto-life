
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0060fbe0(int *param_1)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c [15];
  
  *(undefined1 *)(param_1 + 0x15) = 1;
  if ((DAT_00f3f360 & 1) == 0) {
    DAT_00f3f360 = DAT_00f3f360 | 1;
    _DAT_00f3f300 = 0x3f800000;
    _DAT_00f3f304 = 0;
    _DAT_00f3f308 = 0;
    _DAT_00f3f30c = 0;
    _DAT_00f3f310 = 0;
    _DAT_00f3f314 = 0x3f800000;
    _DAT_00f3f318 = 0;
    _DAT_00f3f31c = 0;
    _DAT_00f3f320 = 0;
    _DAT_00f3f324 = 0;
    _DAT_00f3f328 = 0x3f800000;
    _DAT_00f3f32c = 0;
    _DAT_00f3f330 = 0xbf800000;
    _DAT_00f3f334 = 0;
    _DAT_00f3f338 = 0;
    _DAT_00f3f33c = 0;
    _DAT_00f3f340 = 0;
    _DAT_00f3f344 = 0xbf800000;
    _DAT_00f3f348 = 0;
    _DAT_00f3f34c = 0;
    _DAT_00f3f350 = 0;
    _DAT_00f3f354 = 0;
    _DAT_00f3f358 = 0xbf800000;
    _DAT_00f3f35c = 0;
    _atexit((_func_4879 *)&DAT_0060fe00);
  }
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c[0] = 0.0;
  local_3c[1] = 0.0;
  local_3c[2] = 0.0;
  local_3c[3] = 0.0;
  local_3c[4] = 0.0;
  local_3c[5] = 0.0;
  local_3c[6] = 0.0;
  local_3c[7] = 0.0;
  local_3c[8] = 0.0;
  local_3c[9] = 0.0;
  local_3c[10] = 0.0;
  local_3c[0xb] = 0.0;
  local_3c[0xc] = 0.0;
  local_3c[0xd] = 0.0;
  local_3c[0xe] = 0.0;
  (**(code **)(*param_1 + 0x34))(&DAT_00f3f300,&local_60,6);
  iVar3 = 3;
  pfVar1 = (float *)(param_1 + 0xd);
  pfVar2 = local_3c;
  do {
    iVar3 = iVar3 + -1;
    pfVar1[4] = pfVar2[-0xc] + (float)param_1[0xb];
    *pfVar1 = *pfVar2 - (float)param_1[0xb];
    pfVar1 = pfVar1 + 1;
    pfVar2 = pfVar2 + 5;
  } while (iVar3 != 0);
  return;
}

