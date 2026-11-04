
/* WARNING: Removing unreachable block (ram,0x006c1e72) */

undefined4
FUN_006c1e10(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5,
            int param_6,int param_7,uint param_8,uint param_9,uint *param_10)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  uint local_8;
  int local_4;
  
  lVar5 = CONCAT44(param_6,param_5);
  if ((param_7 != *(int *)(param_4 + 0x28)) || ((param_8 & param_9) == 0xffffffff)) {
    lVar5 = FUN_006c1f50(param_1,&param_8,param_5,param_6,*(int *)(param_4 + 0x28),param_2,param_3);
    if ((lVar5 < 0x100000000) && (lVar5 < 0)) {
      return (int)lVar5;
    }
  }
  param_6 = (int)((ulonglong)lVar5 >> 0x20);
  param_5 = (uint)lVar5;
  if ((param_6 <= *(int *)(param_4 + 0xc)) &&
     ((param_6 < *(int *)(param_4 + 0xc) || (param_5 < *(uint *)(param_4 + 8))))) {
    return 0xffffff77;
  }
  iVar3 = FUN_006c0c50(&local_8,param_8,param_9,*(undefined4 *)(param_4 + 0x20),
                       *(undefined4 *)(param_4 + 0x24));
  if (((-1 < iVar3) && (uVar1 = *(uint *)(param_4 + 0x34), -1 < local_4)) &&
     ((0 < local_4 || (uVar1 <= local_8)))) {
    uVar4 = local_8 - uVar1;
    local_4 = local_4 - (uint)(local_8 < uVar1);
    uVar1 = param_10[1];
    uVar2 = *param_10;
    iVar3 = 0x7fffffff - local_4;
    if (((int)uVar1 < iVar3) || (((int)uVar1 <= iVar3 && (uVar2 <= -uVar4 - 1)))) {
      *param_10 = uVar2 + uVar4;
      param_10[1] = uVar1 + local_4 + (uint)CARRY4(uVar2,uVar4);
      *(uint *)(param_4 + 0x18) = param_8;
      *(uint *)(param_4 + 0x10) = param_5;
      *(uint *)(param_4 + 0x1c) = param_9;
      *(int *)(param_4 + 0x14) = param_6;
      return 0;
    }
  }
  return 0xffffff75;
}

