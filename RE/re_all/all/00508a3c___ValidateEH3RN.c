
/* Library Function - Single Match
    __ValidateEH3RN
   
   Library: Visual Studio 2003 Release */

undefined4 __ValidateEH3RN(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  SIZE_T SVar5;
  int *piVar6;
  LONG LVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  _MEMORY_BASIC_INFORMATION local_24;
  uint *local_8;
  
  puVar3 = param_1;
  puVar8 = (uint *)param_1[2];
  if ((((uint)puVar8 & 3) != 0) ||
     ((local_8 = *(uint **)((int)Self + 8), local_8 <= puVar8 &&
      (puVar8 < *(uint **)((int)Self + 4))))) {
    return 0;
  }
  puVar1 = param_1 + 3;
  if (*puVar1 == 0xffffffff) {
    return 1;
  }
  uVar10 = 0;
  param_1 = (uint *)0x0;
  puVar4 = puVar8;
  do {
    if ((*puVar4 != 0xffffffff) && (uVar10 <= *puVar4)) {
      return 0;
    }
    if (puVar4[1] != 0) {
      param_1 = (uint *)((int)param_1 + 1);
    }
    uVar10 = uVar10 + 1;
    puVar4 = puVar4 + 3;
  } while (uVar10 <= *puVar1);
  if ((param_1 != (uint *)0x0) &&
     ((puVar1 = (uint *)puVar3[-2], puVar1 < local_8 || (puVar3 <= puVar1)))) {
    return 0;
  }
  uVar10 = (uint)puVar8 & 0xfffff000;
  iVar13 = 0;
  if (0 < DAT_00a1ff00) {
    do {
      if ((&DAT_00a1ff08)[iVar13] == uVar10) {
        if (iVar13 < 1) {
          return 1;
        }
        LVar7 = InterlockedExchange((LONG *)&DAT_00a1ff48,1);
        if (LVar7 != 0) {
          return 1;
        }
        if ((&DAT_00a1ff08)[iVar13] == uVar10) goto LAB_00508c37;
        iVar13 = DAT_00a1ff00 + -1;
        if (iVar13 < 0) goto LAB_00508c25;
        goto LAB_00508c15;
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < DAT_00a1ff00);
  }
  SVar5 = VirtualQuery(puVar8,&local_24,0x1c);
  if (SVar5 == 0) {
    return 0xffffffff;
  }
  if (local_24.Type != 0x1000000) {
    return 0xffffffff;
  }
  if (((byte)local_24.Protect & 0xcc) != 0) {
    if (((*(short *)local_24.AllocationBase != 0x5a4d) ||
        (piVar6 = (int *)(*(int *)((int)local_24.AllocationBase + 0x3c) +
                         (int)local_24.AllocationBase), *piVar6 != 0x4550)) ||
       ((short)piVar6[6] != 0x10b)) {
      return 0xffffffff;
    }
    uVar9 = (uint)*(ushort *)(piVar6 + 5);
    if (*(short *)((int)piVar6 + 6) == 0) {
      return 0xffffffff;
    }
    uVar2 = *(uint *)((int)piVar6 + uVar9 + 0x24);
    if (((uVar2 <= (uint)((int)puVar8 - (int)local_24.AllocationBase)) &&
        ((uint)((int)puVar8 - (int)local_24.AllocationBase) <
         *(int *)((int)piVar6 + uVar9 + 0x20) + uVar2)) &&
       ((*(byte *)((int)piVar6 + uVar9 + 0x3f) & 0x80) != 0)) {
      return 0;
    }
  }
  LVar7 = InterlockedExchange((LONG *)&DAT_00a1ff48,1);
  iVar13 = DAT_00a1ff00;
  if (LVar7 != 0) {
    return 1;
  }
  iVar11 = DAT_00a1ff00;
  if (0 < DAT_00a1ff00) {
    puVar8 = (uint *)(&DAT_00a1ff04 + DAT_00a1ff00 * 4);
    do {
      if (*puVar8 == uVar10) break;
      iVar11 = iVar11 + -1;
      puVar8 = puVar8 + -1;
    } while (0 < iVar11);
  }
  if (iVar11 == 0) {
    iVar11 = 0xf;
    if (DAT_00a1ff00 < 0x10) {
      iVar11 = DAT_00a1ff00;
    }
    iVar12 = 0;
    if (-1 < iVar11) {
      do {
        puVar8 = &DAT_00a1ff08 + iVar12;
        uVar9 = *puVar8;
        iVar12 = iVar12 + 1;
        *puVar8 = uVar10;
        uVar10 = uVar9;
      } while (iVar12 <= iVar11);
    }
    if (iVar13 < 0x10) {
      DAT_00a1ff00 = iVar13 + 1;
    }
  }
  InterlockedExchange((LONG *)&DAT_00a1ff48,0);
  return 1;
  while (iVar13 = iVar13 + -1, -1 < iVar13) {
LAB_00508c15:
    if ((&DAT_00a1ff08)[iVar13] == uVar10) break;
  }
  if (iVar13 < 0) {
LAB_00508c25:
    if (DAT_00a1ff00 < 0x10) {
      DAT_00a1ff00 = DAT_00a1ff00 + 1;
    }
    iVar13 = DAT_00a1ff00 + -1;
  }
  else if (iVar13 == 0) goto LAB_00508c4f;
LAB_00508c37:
  iVar11 = 0;
  if (-1 < iVar13) {
    do {
      puVar8 = &DAT_00a1ff08 + iVar11;
      uVar9 = *puVar8;
      iVar11 = iVar11 + 1;
      *puVar8 = uVar10;
      uVar10 = uVar9;
    } while (iVar11 <= iVar13);
  }
LAB_00508c4f:
  InterlockedExchange((LONG *)&DAT_00a1ff48,0);
  return 1;
}

