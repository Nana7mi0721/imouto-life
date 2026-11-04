
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0063fd20(int param_1)

{
  float *pfVar1;
  int iVar2;
  float10 fVar3;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_10;
  float local_c;
  float local_8;
  
  local_44 = 0;
  local_50 = *(float *)(param_1 + 0x474) - *(float *)(param_1 + 0x434);
  pfVar1 = (float *)(param_1 + 0x4c4);
  local_4c = *(float *)(param_1 + 0x478) - *(float *)(param_1 + 0x438);
  local_48 = *(float *)(param_1 + 0x47c) - *(float *)(param_1 + 0x43c);
  *pfVar1 = local_50;
  *(float *)(param_1 + 0x4c8) = local_4c;
  *(float *)(param_1 + 0x4cc) = local_48;
  *(undefined4 *)(param_1 + 0x4d0) = 0;
  fVar3 = (float10)FUN_0063cea0(1,0,2,1);
  local_7c = (float)fVar3;
  fVar3 = (float10)FUN_0063cea0(1,2,2,0);
  local_80 = (float)fVar3;
  fVar3 = (float10)FUN_0063cea0(1,1,2,2);
  local_48 = local_7c;
  local_50 = (float)fVar3;
  local_4c = local_80;
  local_44 = 0;
  fVar3 = (float10)FUN_005fcc30(&local_50);
  local_80 = (float)((float10)_DAT_00804108 / fVar3);
  fVar3 = (float10)FUN_0063cea0(0,0,1,1);
  local_7c = (float)(fVar3 * (float10)local_80);
  fVar3 = (float10)FUN_0063cea0(0,1,2,0);
  local_78 = (float)(fVar3 * (float10)local_80);
  local_74 = local_48 * local_80;
  fVar3 = (float10)FUN_0063cea0(0,2,1,0);
  local_70 = (float)(fVar3 * (float10)local_80);
  fVar3 = (float10)FUN_0063cea0(0,0,2,2);
  local_6c = (float)(fVar3 * (float10)local_80);
  local_68 = local_4c * local_80;
  fVar3 = (float10)FUN_0063cea0(0,1,1,2);
  local_64 = (float)(fVar3 * (float10)local_80);
  fVar3 = (float10)FUN_0063cea0(0,2,2,1);
  local_60 = (float)(fVar3 * (float10)local_80);
  local_5c = local_50 * local_80;
  FUN_005fcc50(&local_5c,&local_60,&local_64,&local_68,&local_6c,&local_70,&local_74,&local_78,
               &local_7c);
  local_80 = local_10 * *pfVar1 +
             local_8 * *(float *)(param_1 + 0x4cc) + local_c * *(float *)(param_1 + 0x4c8);
  fVar3 = (float10)FUN_005fcc30(pfVar1);
  local_58 = (float)fVar3;
  fVar3 = (float10)FUN_005fcc30(pfVar1);
  local_54 = (float)fVar3;
  FUN_005fc500(&local_54,&local_58,&local_80);
  iVar2 = 0;
  *pfVar1 = local_40;
  *(undefined4 *)(param_1 + 0x4c8) = local_3c;
  *(undefined4 *)(param_1 + 0x4cc) = local_38;
  *(undefined4 *)(param_1 + 0x4d0) = local_34;
  do {
    pfVar1[-0x62] = *pfVar1;
    FUN_0063da20(iVar2,*pfVar1);
    iVar2 = iVar2 + 1;
    pfVar1 = pfVar1 + 1;
  } while (iVar2 < 3);
  return;
}

