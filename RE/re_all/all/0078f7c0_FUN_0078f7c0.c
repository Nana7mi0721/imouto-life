
void __thiscall FUN_0078f7c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  uint uVar4;
  float *pfVar5;
  double *pdVar6;
  float *pfVar7;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  uint *puVar8;
  float *pfVar9;
  float local_7c;
  float fStack_78;
  float local_74 [3];
  float local_68;
  float local_64 [2];
  undefined1 local_5c [32];
  float afStack_3c [14];
  
  pfVar9 = local_74;
  (**(code **)(**(int **)(param_1 + 4) + 0xc))
            (&local_7c,local_5c,local_64,local_74 + 2,local_74 + 1,pfVar9,local_64 + 1);
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = (int)&local_68 * param_3 + param_2;
  pfVar7 = afStack_3c;
  puVar8 = (uint *)(iVar2 + 8);
  puVar3 = (ushort *)(iVar2 + 4);
  iVar2 = 3;
  do {
    if (unaff_ESI == 3) {
      uVar4 = (uint)*puVar3;
    }
    else {
      uVar4 = *puVar8;
    }
    if (unaff_EBX == 0) {
      local_74[1] = 0.0;
      pfVar5 = (float *)(uVar4 * unaff_EDI + (int)pfVar9);
      local_7c = *(float *)(iVar1 + 4) * *pfVar5;
      fStack_78 = pfVar5[1] * *(float *)(iVar1 + 8);
      local_74[0] = pfVar5[2] * *(float *)(iVar1 + 0xc);
      *pfVar7 = local_7c;
      pfVar7[1] = fStack_78;
      pfVar7[2] = local_74[0];
    }
    else {
      local_64[1] = 0.0;
      pdVar6 = (double *)(uVar4 * unaff_EDI + (int)pfVar9);
      local_74[2] = (float)*pdVar6 * *(float *)(iVar1 + 4);
      local_68 = (float)pdVar6[1] * *(float *)(iVar1 + 8);
      local_64[0] = (float)pdVar6[2] * *(float *)(iVar1 + 0xc);
      *pfVar7 = local_74[2];
      pfVar7[1] = local_68;
      pfVar7[2] = local_64[0];
    }
    pfVar7[3] = 0.0;
    puVar8 = puVar8 + -1;
    puVar3 = puVar3 + -1;
    pfVar7 = pfVar7 + -4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (**(code **)(**(int **)(param_1 + 8) + 4))(local_5c,param_2,param_3);
  (**(code **)(**(int **)(param_1 + 4) + 0x14))(param_2);
  return;
}

