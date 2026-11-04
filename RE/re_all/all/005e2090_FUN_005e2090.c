
undefined4 FUN_005e2090(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int *in_EAX;
  int iVar7;
  float *pfVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  
  if (in_EAX[0x3f] == 0) {
    iVar7 = FUN_0056e030((in_EAX[3] + 1) * 0x10,
                         "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D9.cpp",0x832);
    in_EAX[0x3f] = iVar7;
    if (iVar7 == 0) {
      return 0;
    }
    if ((short)in_EAX[1] == 0) {
      fVar1 = *(float *)(*(int *)(*in_EAX + 4) + 0x204);
      uVar6 = in_EAX[3];
      pfVar11 = (float *)(iVar7 + 0xfU & 0xfffffff0);
      pfVar12 = (float *)(in_EAX[0x42] + 0xfU & 0xfffffff0);
      uVar9 = 0;
      if (3 < (int)uVar6) {
        iVar7 = (uVar6 - 4 >> 2) + 1;
        uVar9 = iVar7 * 4;
        pfVar8 = pfVar12 + 6;
        pfVar10 = pfVar11 + 8;
        do {
          fVar2 = pfVar8[-1];
          fVar3 = *pfVar8;
          fVar4 = pfVar8[-5];
          fVar5 = pfVar8[-4];
          *pfVar11 = *pfVar12 + pfVar8[-2] * fVar1;
          pfVar11[1] = fVar4 + fVar2 * fVar1;
          pfVar11[2] = fVar5 + fVar1 * fVar3;
          fVar2 = pfVar8[7];
          fVar3 = pfVar8[8];
          fVar4 = pfVar8[3];
          fVar5 = pfVar8[4];
          pfVar10[-4] = pfVar8[2] + pfVar8[6] * fVar1;
          pfVar10[-3] = fVar4 + fVar2 * fVar1;
          pfVar10[-2] = fVar5 + fVar3 * fVar1;
          fVar2 = pfVar8[0xf];
          fVar3 = pfVar8[0x10];
          fVar4 = pfVar8[0xb];
          fVar5 = pfVar8[0xc];
          *pfVar10 = pfVar8[10] + pfVar8[0xe] * fVar1;
          pfVar10[1] = fVar4 + fVar2 * fVar1;
          pfVar10[2] = fVar5 + fVar3 * fVar1;
          fVar2 = pfVar8[0x17];
          fVar3 = pfVar8[0x18];
          pfVar11 = pfVar11 + 0x10;
          pfVar12 = pfVar12 + 0x20;
          iVar7 = iVar7 + -1;
          fVar4 = pfVar8[0x13];
          fVar5 = pfVar8[0x14];
          pfVar10[4] = pfVar8[0x12] + pfVar8[0x16] * fVar1;
          pfVar10[5] = fVar4 + fVar2 * fVar1;
          pfVar10[6] = fVar5 + fVar3 * fVar1;
          pfVar8 = pfVar8 + 0x20;
          pfVar10 = pfVar10 + 0x10;
        } while (iVar7 != 0);
      }
      if (uVar9 < uVar6) {
        iVar7 = uVar6 - uVar9;
        pfVar8 = pfVar12 + 6;
        do {
          iVar7 = iVar7 + -1;
          fVar2 = pfVar8[-1];
          fVar3 = *pfVar8;
          fVar4 = pfVar8[-5];
          fVar5 = pfVar8[-4];
          *pfVar11 = *pfVar12 + pfVar8[-2] * fVar1;
          pfVar11[1] = fVar4 + fVar2 * fVar1;
          pfVar11[2] = fVar5 + fVar3 * fVar1;
          pfVar8 = pfVar8 + 8;
          pfVar11 = pfVar11 + 4;
          pfVar12 = pfVar12 + 8;
        } while (iVar7 != 0);
      }
    }
  }
  return 1;
}

