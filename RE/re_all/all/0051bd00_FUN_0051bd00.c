
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0051bd00(int param_1)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  byte local_8 [8];
  
  iVar3 = 0;
  pfVar2 = (float *)(param_1 + 8);
  while( true ) {
    fVar1 = pfVar2[-1];
    local_8[iVar3] = 0;
    if ((double)*pfVar2 * _DAT_00a38bf8 +
        (double)pfVar2[-2] * _DAT_00a38be8 + (double)fVar1 * _DAT_00a38bf0 + _DAT_00a38c00 < 0.0) {
      local_8[iVar3] = 2;
    }
    if ((double)*pfVar2 * _DAT_00a38c18 +
        (double)pfVar2[-2] * _DAT_00a38c08 + (double)pfVar2[-1] * _DAT_00a38c10 + _DAT_00a38c20 <
        0.0) {
      local_8[iVar3] = local_8[iVar3] | 1;
    }
    if ((double)*pfVar2 * _DAT_00a38c38 +
        (double)pfVar2[-2] * _DAT_00a38c28 + (double)pfVar2[-1] * _DAT_00a38c30 + _DAT_00a38c40 <
        0.0) {
      local_8[iVar3] = local_8[iVar3] | 8;
    }
    if ((double)*pfVar2 * _DAT_00a38c58 +
        (double)pfVar2[-2] * _DAT_00a38c48 + (double)pfVar2[-1] * _DAT_00a38c50 + _DAT_00a38c60 <
        0.0) {
      local_8[iVar3] = local_8[iVar3] | 4;
    }
    if ((double)*pfVar2 * _DAT_00a38c78 +
        (double)pfVar2[-2] * _DAT_00a38c68 + (double)pfVar2[-1] * _DAT_00a38c70 + _DAT_00a38c80 <
        0.0) {
      local_8[iVar3] = local_8[iVar3] | 0x20;
    }
    if ((double)*pfVar2 * _DAT_00a38c98 +
        (double)pfVar2[-2] * _DAT_00a38c88 + (double)pfVar2[-1] * _DAT_00a38c90 + _DAT_00a38ca0 <
        0.0) {
      local_8[iVar3] = local_8[iVar3] | 0x10;
    }
    if (local_8[iVar3] == 0) break;
    iVar3 = iVar3 + 1;
    pfVar2 = pfVar2 + 3;
    if (7 < iVar3) {
      if (((((((local_8[0] & 1) == 0) || ((local_8[1] & 1) == 0)) || ((local_8[2] & 1) == 0)) ||
           ((((local_8[3] & 1) == 0 || ((local_8[4] & 1) == 0)) ||
            (((local_8[5] & 1) == 0 || (((local_8[6] & 1) == 0 || ((local_8[7] & 1) == 0)))))))) &&
          (((((local_8[0] & 2) == 0 ||
             (((((local_8[1] & 2) == 0 || ((local_8[2] & 2) == 0)) || ((local_8[3] & 2) == 0)) ||
              (((local_8[4] & 2) == 0 || ((local_8[5] & 2) == 0)))))) ||
            (((local_8[6] & 2) == 0 || ((local_8[7] & 2) == 0)))) &&
           ((((((local_8[0] & 4) == 0 || ((local_8[1] & 4) == 0)) || ((local_8[2] & 4) == 0)) ||
             (((((local_8[3] & 4) == 0 || ((local_8[4] & 4) == 0)) || ((local_8[5] & 4) == 0)) ||
              (((local_8[6] & 4) == 0 || ((local_8[7] & 4) == 0)))))) &&
            (((((local_8[0] & 8) == 0 || (((local_8[1] & 8) == 0 || ((local_8[2] & 8) == 0)))) ||
              ((local_8[3] & 8) == 0)) ||
             (((((local_8[4] & 8) == 0 || ((local_8[5] & 8) == 0)) || ((local_8[6] & 8) == 0)) ||
              ((local_8[7] & 8) == 0)))))))))) &&
         ((((((local_8[0] & 0x10) == 0 || ((local_8[1] & 0x10) == 0)) ||
            (((local_8[2] & 0x10) == 0 || (((local_8[3] & 0x10) == 0 || ((local_8[4] & 0x10) == 0)))
             ))) || (((local_8[5] & 0x10) == 0 ||
                     (((local_8[6] & 0x10) == 0 || ((local_8[7] & 0x10) == 0)))))) &&
          (((((local_8[0] & 0x20) == 0 ||
             (((((local_8[1] & 0x20) == 0 || ((local_8[2] & 0x20) == 0)) ||
               ((local_8[3] & 0x20) == 0)) ||
              (((local_8[4] & 0x20) == 0 || ((local_8[5] & 0x20) == 0)))))) ||
            ((local_8[6] & 0x20) == 0)) || ((local_8[7] & 0x20) == 0)))))) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

