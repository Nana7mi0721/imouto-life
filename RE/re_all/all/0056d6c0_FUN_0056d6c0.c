
void FUN_0056d6c0(uint *param_1,uint *param_2,longlong *param_3)

{
  uint *puVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = *param_1;
  uVar4 = *param_2;
  *(undefined4 *)param_3 = 0;
  *(undefined4 *)((int)param_3 + 4) = 0;
  *(undefined4 *)(param_3 + 1) = 0;
  *(undefined4 *)((int)param_3 + 0xc) = 0;
  *param_3 = (ulonglong)uVar2 * (ulonglong)uVar4;
  lVar3 = (ulonglong)uVar2 * (ulonglong)param_2[1];
  uVar6 = (uint)((ulonglong)lVar3 >> 0x20);
  uVar4 = (uint)lVar3;
  puVar1 = (uint *)((int)param_3 + 4);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar4;
  puVar1 = (uint *)(param_3 + 1);
  uVar4 = (uint)CARRY4(uVar2,uVar4);
  uVar2 = *puVar1;
  uVar5 = *puVar1 + uVar6;
  *puVar1 = uVar5 + uVar4;
  *(int *)((int)param_3 + 0xc) =
       *(int *)((int)param_3 + 0xc) + (uint)(CARRY4(uVar2,uVar6) || CARRY4(uVar5,uVar4));
  uVar4 = param_1[1];
  lVar3 = (ulonglong)uVar4 * (ulonglong)*param_2;
  uVar7 = (uint)((ulonglong)lVar3 >> 0x20);
  uVar5 = (uint)lVar3;
  puVar1 = (uint *)((int)param_3 + 4);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar5;
  puVar1 = (uint *)(param_3 + 1);
  uVar5 = (uint)CARRY4(uVar2,uVar5);
  uVar2 = *puVar1;
  uVar6 = *puVar1 + uVar7;
  *puVar1 = uVar6 + uVar5;
  *(int *)((int)param_3 + 0xc) =
       *(int *)((int)param_3 + 0xc) + (uint)(CARRY4(uVar2,uVar7) || CARRY4(uVar6,uVar5));
  lVar3 = (ulonglong)uVar4 * (ulonglong)param_2[1];
  uVar4 = (uint)lVar3;
  puVar1 = (uint *)(param_3 + 1);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + uVar4;
  *(int *)((int)param_3 + 0xc) =
       *(int *)((int)param_3 + 0xc) + (int)((ulonglong)lVar3 >> 0x20) + (uint)CARRY4(uVar2,uVar4);
  return;
}

