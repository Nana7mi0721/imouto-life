
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0063b190(int *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int *piVar5;
  undefined1 uStack00000000;
  float fStack_c;
  float afStack_8 [2];
  
  param_1[0x3a] = 2;
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x4f] = 0;
  param_1[0x50] = 0;
  param_1[0x51] = 0;
  param_1[0x52] = 0;
  param_1[0x53] = 0;
  param_1[0x55] = 0x3f800000;
  param_1[0x56] = 0x3f800000;
  param_1[0x57] = 0x3f800000;
  param_1[0x58] = 0;
  param_1[0x59] = 0x3f800000;
  param_1[0x5a] = 0x3f800000;
  param_1[0x5b] = 0x3f800000;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  param_1[0x6c] = 0;
  param_1[0x6d] = 0;
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0x3f000000;
  param_1[0x78] = (int)param_2[0x1b];
  param_1[0x79] = (int)param_2[0x1c];
  param_1[0x7a] = (int)param_2[1];
  param_1[0x80] = 0;
  param_1[0x81] = 0;
  *(undefined1 *)(param_1 + 0x73) = *(undefined1 *)(param_2 + 0x1d);
  param_1[0x74] = (int)param_2[0x1e];
  param_1[0x75] = (int)param_2[0x1f];
  param_1[0x76] = (int)param_2[0x20];
  param_1[0x77] = (int)param_2[0x21];
  if ((int *)param_1[0x7a] == (int *)0x0) {
    param_1[1] = (int)param_2[2];
    param_1[2] = (int)param_2[3];
    param_1[3] = (int)param_2[4];
    param_1[4] = (int)param_2[5];
    param_1[5] = (int)param_2[6];
    param_1[6] = (int)param_2[7];
    param_1[7] = (int)param_2[8];
    param_1[8] = (int)param_2[9];
    param_1[9] = (int)param_2[10];
    param_1[10] = (int)param_2[0xb];
    param_1[0xb] = (int)param_2[0xc];
    param_1[0xc] = (int)param_2[0xd];
    param_1[0xd] = (int)param_2[0xe];
    param_1[0xe] = (int)param_2[0xf];
    param_1[0xf] = (int)param_2[0x10];
    param_1[0x10] = (int)param_2[0x11];
  }
  else {
    (**(code **)(*(int *)param_1[0x7a] + 4))(param_1 + 1);
  }
  param_1[0x11] = param_1[1];
  param_1[0x12] = param_1[2];
  param_1[0x13] = param_1[3];
  param_1[0x14] = param_1[4];
  param_1[0x15] = param_1[5];
  param_1[0x16] = param_1[6];
  param_1[0x17] = param_1[7];
  param_1[0x18] = param_1[8];
  param_1[0x19] = param_1[9];
  param_1[0x1a] = param_1[10];
  param_1[0x1b] = param_1[0xb];
  param_1[0x1c] = param_1[0xc];
  param_1[0x1d] = param_1[0xd];
  param_1[0x1e] = param_1[0xe];
  param_1[0x1f] = param_1[0xf];
  param_1[0x20] = param_1[0x10];
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x37] = (int)param_2[0x19];
  param_1[0x38] = (int)param_2[0x1a];
  (**(code **)(*param_1 + 8))(param_2[0x12]);
  param_1[0x82] = DAT_00f3f81c;
  DAT_00f3f81c = DAT_00f3f81c + 1;
  if (*param_2 == _DAT_007d5344) {
    param_1[0x54] = 0;
    param_1[0x32] = param_1[0x32] | 1;
  }
  else {
    fVar1 = _DAT_00804108 / *param_2;
    param_1[0x32] = param_1[0x32] & 0xfffffffe;
    param_1[0x54] = (int)fVar1;
  }
  if (param_2[0x15] == _DAT_007d5344) {
    fVar1 = _DAT_007d5344;
  }
  else {
    fVar1 = _DAT_00804108 / param_2[0x15];
  }
  if (param_2[0x14] == _DAT_007d5344) {
    fVar2 = _DAT_007d5344;
  }
  else {
    fVar2 = _DAT_00804108 / param_2[0x14];
  }
  if (param_2[0x13] == _DAT_007d5344) {
    fVar3 = _DAT_007d5344;
  }
  else {
    fVar3 = _DAT_00804108 / param_2[0x13];
  }
  param_1[0x65] = (int)fVar3;
  param_1[0x68] = 0;
  fStack_c = 1.0;
  param_1[0x66] = (int)fVar2;
  param_1[0x67] = (int)fVar1;
  afStack_8[0] = param_2[0x18];
  if (_DAT_007d5344 <= param_2[0x17]) {
    pfVar4 = &fStack_c;
    if (param_2[0x17] <= _DAT_00804108) {
      pfVar4 = (float *)register0x00000010;
    }
  }
  else {
    pfVar4 = afStack_8 + -2;
  }
  param_1[0x71] = (int)*pfVar4;
  fStack_c = 0.0;
  piVar5 = (int *)FUN_0063cee0(afStack_8,&fStack_c,&uStack00000000);
  param_1[0x72] = *piVar5;
  FUN_0063c330();
  return;
}

