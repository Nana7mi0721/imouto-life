
undefined4 FUN_005dfb70(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *in_EAX;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  int *local_14;
  int local_10;
  
  if (in_EAX[0x3e] != 0) {
    return 1;
  }
  iVar2 = *(int *)(*in_EAX + 0x4c);
  iVar3 = *(int *)(*in_EAX + 0x58);
  iVar1 = iVar2 + 4;
  *(short *)(in_EAX + 2) = (short)(iVar1 * 0x10);
  iVar5 = FUN_0056e030(in_EAX[3] * iVar1 * 0x10,
                       "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxModelD3D9.cpp",0x417);
  in_EAX[0x3e] = iVar5;
  if (iVar5 == 0) {
    return 0;
  }
  iVar4 = *(int *)(*in_EAX + 0x5c);
  local_14 = (int *)in_EAX[0x3c];
  iVar10 = in_EAX[3];
  if (0 < iVar10) {
    puVar8 = (undefined4 *)(iVar5 + 0x1c);
    local_10 = iVar10;
    do {
      iVar5 = *local_14 * iVar3 + iVar4;
      puVar8[-1] = *(undefined4 *)(iVar5 + 8);
      *puVar8 = *(undefined4 *)(iVar5 + 0xc);
      if (0 < iVar2) {
        puVar6 = puVar8 + 2;
        puVar7 = (undefined4 *)(iVar5 + 0x18);
        iVar5 = iVar2;
        do {
          puVar6[-1] = puVar7[-1];
          iVar5 = iVar5 + -1;
          *puVar6 = *puVar7;
          puVar6[1] = 0x3f800000;
          puVar6[2] = 0x3f800000;
          puVar6 = puVar6 + 4;
          puVar7 = puVar7 + 2;
        } while (iVar5 != 0);
      }
      local_14 = local_14 + 1;
      puVar8 = puVar8 + iVar1 * 4;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  if ((short)in_EAX[1] == 0) {
    puVar8 = (undefined4 *)in_EAX[0x3e];
    puVar6 = (undefined4 *)(in_EAX[0x42] + 0xfU & 0xfffffff0);
    if (0 < iVar10) {
      puVar7 = puVar8 + 3;
      puVar9 = puVar6 + 4;
      do {
        *puVar8 = *puVar6;
        puVar8[1] = puVar6[1];
        puVar8[2] = puVar6[2];
        *puVar7 = *puVar9;
        puVar7[1] = puVar9[1];
        puVar7[2] = puVar9[2];
        puVar6 = puVar6 + 8;
        puVar9 = puVar9 + 8;
        puVar8 = puVar8 + iVar1 * 4;
        puVar7 = puVar7 + iVar1 * 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  return 1;
}

