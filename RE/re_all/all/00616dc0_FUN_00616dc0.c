
void __thiscall FUN_00616dc0(float param_1,float param_2,float param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float10 fVar8;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = param_3;
  iVar4 = (int)param_2;
  param_2 = *(float *)((int)param_1 + 0x29c);
  local_34 = param_1;
  if (-1 < (int)param_2 + -1) {
    pfVar5 = (float *)((int)param_1 + 0x2c + ((int)param_2 + -1) * 0xa4);
    do {
      pfVar1 = pfVar5 + -10;
      fVar8 = (float10)FUN_005fcc30(pfVar1);
      param_3 = (float)(fVar8 + (float10)*(float *)(iVar4 + 0x38));
      fVar8 = (float10)FUN_005fcc30(pfVar1);
      local_54 = (float)(fVar8 + (float10)*(float *)(iVar4 + 0x34));
      fVar8 = (float10)FUN_005fcc30(pfVar1);
      local_50 = (float)(fVar8 + (float10)*(float *)(iVar4 + 0x30));
      FUN_005fc500(&local_50,&local_54,&param_3);
      pfVar1 = pfVar5 + -6;
      pfVar5[2] = local_30;
      pfVar5[3] = local_2c;
      pfVar5[4] = local_28;
      pfVar5[5] = local_24;
      fVar8 = (float10)FUN_005fcc30(pfVar1);
      local_4c = (float)(fVar8 + (float10)*(float *)((int)fVar2 + 0x38));
      fVar8 = (float10)FUN_005fcc30(pfVar1);
      local_48 = (float)(fVar8 + (float10)*(float *)((int)fVar2 + 0x34));
      fVar8 = (float10)FUN_005fcc30(pfVar1);
      local_44 = (float)(fVar8 + (float10)*(float *)((int)fVar2 + 0x30));
      FUN_005fc500(&local_44,&local_48,&local_4c);
      pfVar5[-2] = local_20;
      pfVar5[-1] = local_1c;
      *pfVar5 = local_18;
      pfVar5[1] = local_14;
      local_40 = pfVar5[4] - *pfVar5;
      local_3c = pfVar5[3] - pfVar5[-1];
      local_38 = pfVar5[2] - pfVar5[-2];
      FUN_005fc500(&local_38,&local_3c,&local_40);
      pfVar5[0x16] = (float)((int)pfVar5[0x16] + 1);
      param_2 = (float)((int)param_2 + -1);
      pfVar5[10] = local_10 * pfVar5[6] + local_c * pfVar5[7] + local_8 * pfVar5[8];
      pfVar5 = pfVar5 + -0x29;
    } while (param_2 != 0.0);
  }
  fVar2 = local_34;
  param_2 = (float)(*(int *)((int)local_34 + 0x29c) + -1);
  if (-1 < (int)param_2) {
    pfVar5 = (float *)((int)local_34 + 0x48 + (int)param_2 * 0xa4);
    do {
      iVar4 = (int)param_2;
      if (pfVar5[3] <= *(float *)((int)fVar2 + 0x2a0)) {
        param_2 = pfVar5[1] * pfVar5[3];
        param_3 = *pfVar5 * pfVar5[3];
        local_34 = pfVar5[-1] * pfVar5[3];
        FUN_005fc500(&local_34,&param_3,&param_2);
        local_38 = pfVar5[-3] - local_8;
        local_3c = pfVar5[-4] - local_c;
        local_40 = pfVar5[-5] - local_10;
        FUN_005fc500(&local_40,&local_3c,&local_38);
        param_2 = pfVar5[-7] - local_18;
        param_3 = pfVar5[-8] - local_1c;
        local_34 = pfVar5[-9] - local_20;
        FUN_005fc500(&local_34,&param_3,&param_2);
        if (local_28 * local_28 + local_2c * local_2c + local_30 * local_30 <=
            *(float *)((int)fVar2 + 0x2a0) * *(float *)((int)fVar2 + 0x2a0)) {
          if (DAT_00f3f3e4 != (code *)0x0) {
            (*DAT_00f3f3e4)(pfVar5 + -0x11,*(undefined4 *)((int)fVar2 + 0x294),
                            *(undefined4 *)((int)fVar2 + 0x298));
          }
        }
        else {
          FUN_006171e0(iVar4);
        }
      }
      else {
        FUN_006168d0(pfVar5 + -0x11);
        iVar3 = *(int *)((int)fVar2 + 0x29c) + -1;
        if (iVar4 != iVar3) {
          pfVar1 = (float *)((int)fVar2 + iVar3 * 0xa4);
          pfVar7 = pfVar5 + -0x11;
          pfVar6 = pfVar1;
          for (iVar4 = 0x29; pfVar6 = pfVar6 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
            *pfVar7 = *pfVar6;
            pfVar7 = pfVar7 + 1;
          }
          pfVar1[0x1c] = 0.0;
          pfVar1[0x1d] = 0.0;
          *(undefined1 *)(pfVar1 + 0x1e) = 0;
          pfVar1[0x1f] = 0.0;
          pfVar1[0x20] = 0.0;
          pfVar1[0x21] = 0.0;
          iVar4 = (int)param_2;
        }
        *(int *)((int)fVar2 + 0x29c) = *(int *)((int)fVar2 + 0x29c) + -1;
      }
      param_2 = (float)(iVar4 + -1);
      pfVar5 = pfVar5 + -0x29;
    } while (-1 < (int)param_2);
  }
  return;
}

