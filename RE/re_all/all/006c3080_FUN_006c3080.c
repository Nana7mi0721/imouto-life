
undefined8 FUN_006c3080(int param_1,uint param_2,int param_3,int *param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  bool bVar8;
  uint local_8;
  int local_4;
  
  iVar7 = *(int *)(param_1 + 0x18);
  piVar1 = (int *)(param_1 + 0x1c);
  param_1 = 0;
  if (0 < iVar7) {
    puVar6 = (uint *)(*piVar1 + 0x34);
    do {
      uVar4 = puVar6[-4];
      uVar5 = puVar6[-5];
      uVar2 = *puVar6;
      FUN_006c0c50(&local_8,puVar6[-7],puVar6[-6],uVar5,uVar4);
      bVar8 = local_8 < uVar2;
      local_8 = local_8 - uVar2;
      local_4 = (local_4 - ((int)uVar2 >> 0x1f)) - (uint)bVar8;
      if ((param_3 < local_4) || ((param_3 <= local_4 && (param_2 < local_8)))) {
        uVar3 = param_2 + uVar2;
        iVar7 = param_3 + ((int)uVar2 >> 0x1f) + (uint)CARRY4(param_2,uVar2);
        if ((0x7fffffff - iVar7 <= (int)uVar4) &&
           ((0x7fffffff - iVar7 < (int)uVar4 || (-uVar3 - 1 < uVar5)))) {
          bVar8 = CARRY4(uVar3,uVar5);
          uVar3 = uVar3 + uVar5;
          iVar7 = iVar7 + uVar4 + 0x80000000 + (uint)bVar8;
          uVar5 = 0;
          uVar4 = 0x80000000;
        }
        *param_4 = param_1;
        return CONCAT44(uVar4 + iVar7 + (uint)CARRY4(uVar5,uVar3),uVar5 + uVar3);
      }
      bVar8 = param_2 < local_8;
      param_2 = param_2 - local_8;
      param_3 = (param_3 - local_4) - (uint)bVar8;
      param_1 = param_1 + 1;
      puVar6 = puVar6 + 0x58;
    } while (param_1 < iVar7);
  }
  return 0xffffffffffffffff;
}

