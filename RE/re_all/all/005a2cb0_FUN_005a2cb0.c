
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a2cb0(void)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = 0;
  if (-1 < DAT_00e7989c) {
    iVar4 = 0x24;
    iVar2 = 0xb;
    pfVar1 = (float *)&DAT_00e79cc8;
    do {
      if ((&DAT_00e798a0)[iVar3] != 0) {
        local_10 = pfVar1[-1] * DAT_00e804b4;
        local_c = *pfVar1 * DAT_00e804b8;
        local_8 = pfVar1[1] * DAT_00e804bc;
        local_4 = pfVar1[2] * DAT_00e804c0;
        if (iVar3 < 4) {
          FUN_0059cb80(&DAT_00ddb600,0,0,iVar4 + -0x12,&local_10,1,1);
          FUN_0059cb80(&DAT_00ddb600,3,0,iVar2,&local_10,1,1);
        }
        if (iVar3 < 6) {
          FUN_0059cb80(&DAT_00ddb600,3,0,iVar4,&local_10,1,1);
        }
      }
      iVar3 = iVar3 + 1;
      pfVar1 = pfVar1 + 0x1a;
      iVar2 = iVar2 + 3;
      iVar4 = iVar4 + 7;
    } while (iVar3 <= DAT_00e7989c);
  }
  local_10 = _DAT_00e7988c * DAT_00e804b4 + DAT_00e804d4;
  local_c = _DAT_00e79890 * DAT_00e804b8 + DAT_00e804d8;
  local_8 = _DAT_00e79894 * DAT_00e804bc + DAT_00e804dc;
  local_4 = _DAT_00e79898 * DAT_00e804c0 + DAT_00e804e0;
  FUN_0059cb80(&DAT_00ddb600,0,0,1,&local_10,1,1);
  FUN_0059cb80(&DAT_00ddb600,3,0,1,&local_10,1,1);
  return;
}

