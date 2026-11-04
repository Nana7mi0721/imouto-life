
void FUN_005eb960(int param_1)

{
  int iVar1;
  double *pdVar2;
  float *pfVar3;
  int in_EAX;
  int *piVar4;
  int iVar5;
  float *pfVar6;
  int unaff_EDI;
  int local_d0;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  double local_70;
  undefined1 local_68 [100];
  
  pfVar6 = *(float **)(DAT_00ef1b9c + 8);
  if (DAT_00a380c4 == 0) {
    iVar5 = 0;
    if (0 < *(int *)(unaff_EDI + 0x14)) {
      iVar1 = *(int *)(in_EAX + 0x1e8);
      piVar4 = (int *)(unaff_EDI + 0x18);
      do {
        pfVar3 = *(float **)(iVar1 + *piVar4 * 4);
        iVar5 = iVar5 + 1;
        *pfVar6 = *pfVar3;
        piVar4 = piVar4 + 1;
        pfVar6[1] = pfVar3[1];
        pfVar6[2] = pfVar3[2];
        pfVar6[3] = pfVar3[3];
        pfVar6[4] = pfVar3[4];
        pfVar6[5] = pfVar3[5];
        pfVar6[6] = pfVar3[6];
        pfVar6[7] = pfVar3[7];
        pfVar6[8] = pfVar3[8];
        pfVar6[9] = pfVar3[9];
        pfVar6[10] = pfVar3[10];
        pfVar6[0xb] = pfVar3[0xb];
        pfVar6 = pfVar6 + 0xc;
      } while (iVar5 < *(int *)(unaff_EDI + 0x14));
      *(undefined4 *)(DAT_00ef1b9c + 0xc) = 1;
      return;
    }
  }
  else if (param_1 == 0) {
    FUN_00582890(local_68,&DAT_00a38358);
    local_d0 = 0;
    if (0 < *(int *)(unaff_EDI + 0x14)) {
      iVar5 = *(int *)(in_EAX + 0x1e8);
      piVar4 = (int *)(unaff_EDI + 0x18);
      do {
        FUN_00582380(&local_c8,*(undefined4 *)(iVar5 + *piVar4 * 4),local_68);
        *pfVar6 = (float)local_c8;
        local_d0 = local_d0 + 1;
        pfVar6[1] = (float)local_c0;
        pfVar6[2] = (float)local_b8;
        piVar4 = piVar4 + 1;
        pfVar6[3] = (float)local_b0;
        pfVar6[4] = (float)local_a8;
        pfVar6[5] = (float)local_a0;
        pfVar6[6] = (float)local_98;
        pfVar6[7] = (float)local_90;
        pfVar6[8] = (float)local_88;
        pfVar6[9] = (float)local_80;
        pfVar6[10] = (float)local_78;
        pfVar6[0xb] = (float)local_70;
        pfVar6 = pfVar6 + 0xc;
      } while (local_d0 < *(int *)(unaff_EDI + 0x14));
    }
    FUN_005b9490(&DAT_00a054c0);
  }
  else {
    iVar5 = 0;
    if (0 < *(int *)(unaff_EDI + 0x14)) {
      iVar1 = *(int *)(in_EAX + 0x1e8);
      piVar4 = (int *)(unaff_EDI + 0x18);
      do {
        pdVar2 = *(double **)(iVar1 + *piVar4 * 4);
        iVar5 = iVar5 + 1;
        *pfVar6 = (float)*pdVar2;
        piVar4 = piVar4 + 1;
        pfVar6[1] = (float)pdVar2[1];
        pfVar6[2] = (float)pdVar2[2];
        pfVar6[3] = (float)pdVar2[3];
        pfVar6[4] = (float)pdVar2[4];
        pfVar6[5] = (float)pdVar2[5];
        pfVar6[6] = (float)pdVar2[6];
        pfVar6[7] = (float)pdVar2[7];
        pfVar6[8] = (float)pdVar2[8];
        pfVar6[9] = (float)pdVar2[9];
        pfVar6[10] = (float)pdVar2[10];
        pfVar6[0xb] = (float)pdVar2[0xb];
        pfVar6 = pfVar6 + 0xc;
      } while (iVar5 < *(int *)(unaff_EDI + 0x14));
      *(undefined4 *)(DAT_00ef1b9c + 0xc) = 1;
      return;
    }
  }
  *(undefined4 *)(DAT_00ef1b9c + 0xc) = 1;
  return;
}

