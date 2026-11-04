
void __thiscall FUN_0078fb90(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float *pfVar4;
  double *pdVar5;
  float *pfVar6;
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  ushort *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
  float *pfVar10;
  int iVar11;
  float local_4c;
  float local_48;
  float fStack_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34 [2];
  undefined1 local_2c [40];
  
  pfVar10 = local_34 + 1;
  puVar9 = &local_40;
  (**(code **)(**(int **)(param_1 + 4) + 0xc))
            (&local_48,local_2c,local_34,&local_4c,&local_3c,puVar9,pfVar10,&local_38);
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = param_2 * param_3 + unaff_EDI;
  iVar11 = 3;
  puVar8 = (uint *)(iVar2 + 8);
  puVar7 = (ushort *)(iVar2 + 4);
  pfVar6 = (float *)(param_1 + 0x2c);
  do {
    if (unaff_ESI == 3) {
      uVar3 = (uint)*puVar7;
    }
    else {
      uVar3 = *puVar8;
    }
    if (unaff_EBX == 0) {
      local_40 = 0;
      pfVar4 = (float *)(uVar3 * (int)puVar9 + (int)pfVar10);
      local_4c = *(float *)(iVar1 + 4) * *pfVar4;
      local_48 = pfVar4[1] * *(float *)(iVar1 + 8);
      fStack_44 = pfVar4[2] * *(float *)(iVar1 + 0xc);
      *pfVar6 = local_4c;
      pfVar6[1] = local_48;
      pfVar6[2] = fStack_44;
    }
    else {
      local_34[1] = 0.0;
      pdVar5 = (double *)(uVar3 * (int)puVar9 + (int)pfVar10);
      local_3c = (float)*pdVar5 * *(float *)(iVar1 + 4);
      local_38 = (float)pdVar5[1] * *(float *)(iVar1 + 8);
      local_34[0] = (float)pdVar5[2] * *(float *)(iVar1 + 0xc);
      *pfVar6 = local_3c;
      pfVar6[1] = local_38;
      pfVar6[2] = local_34[0];
    }
    pfVar6[3] = 0.0;
    puVar8 = puVar8 + -1;
    puVar7 = puVar7 + -1;
    pfVar6 = pfVar6 + -4;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  (**(code **)(**(int **)(param_1 + 8) + 4))(param_1 + 0xc,param_2,param_3);
  (**(code **)(**(int **)(param_1 + 4) + 0x14))(param_2);
  return;
}

