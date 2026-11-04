
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057b670(uint param_1,undefined4 param_2)

{
  uint *puVar1;
  int *piVar2;
  double dVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_2c;
  undefined1 local_28 [16];
  undefined1 local_18 [8];
  int local_10;
  
  if (((((DAT_00cc5680 == 0) || ((int)param_1 < 0)) || ((param_1 & 0x7c000000) != DAT_00cc56a8)) ||
      ((DAT_00cc56b0 <= (int)(param_1 & 0xffff) ||
       (piVar2 = *(int **)(DAT_00cc5684 + (param_1 & 0xffff) * 4), piVar2 == (int *)0x0)))) ||
     ((*piVar2 * 0x10000 != (param_1 & 0x3ff0000) || (piVar2[4] != 0)))) {
    return 0xffffffff;
  }
  if (piVar2[0xd] == 0) {
    FUN_005da6d0(piVar2,param_2);
  }
  else {
    FUN_005fc490(piVar2[0xe],local_18);
    if (piVar2[0x33] == 0) {
      uVar8 = FUN_00550090(0);
      local_2c = (int)((ulonglong)uVar8 >> 0x20);
      uVar4 = (uint)uVar8;
      if ((*(double *)(piVar2 + 0x20) < _DAT_007d81e0) ||
         (_DAT_007d81d8 < *(double *)(piVar2 + 0x20))) {
        local_38 = uVar4 - piVar2[0x10];
        local_34 = (local_2c - piVar2[0x11]) - (uint)(uVar4 < (uint)piVar2[0x10]);
        local_40 = FUN_0050e240(*(double *)(piVar2 + 0x20) * _DAT_007d5fe0);
        local_3c = local_40 >> 0x1f;
        FUN_0056d6c0(&local_38,&local_40,local_28);
        local_40 = 0x10000;
        local_3c = 0;
        FUN_0056d730(local_28,&local_40,&local_38);
        puVar1 = (uint *)(piVar2 + 0x12);
        uVar6 = *puVar1;
        *puVar1 = *puVar1 + local_38;
        piVar2[0x13] = piVar2[0x13] + local_34 + (uint)CARRY4(uVar6,local_38);
      }
      else {
        uVar5 = uVar4 - piVar2[0x10];
        puVar1 = (uint *)(piVar2 + 0x12);
        uVar6 = *puVar1;
        *puVar1 = *puVar1 + uVar5;
        piVar2[0x13] = piVar2[0x13] +
                       ((local_2c - piVar2[0x11]) - (uint)(uVar4 < (uint)piVar2[0x10])) +
                       (uint)CARRY4(uVar6,uVar5);
      }
      local_38 = piVar2[0x12];
      dVar3 = *(double *)(piVar2 + 0x18) * _DAT_007d5fe0;
      local_34 = piVar2[0x13];
      *(undefined8 *)(piVar2 + 0x10) = uVar8;
      local_40 = FUN_0050e240(dVar3);
      local_3c = local_40 >> 0x1f;
      FUN_0056d6c0(&local_38,&local_40,local_28);
      local_40 = 0x42400000;
      local_3c = 0xf;
      FUN_0056d730(local_28,&local_40,&local_38);
      uVar6 = local_38;
      if (local_10 <= (int)local_38) {
        if ((*(byte *)(piVar2 + 0xc) & 2) == 0) {
          uVar6 = local_10 - 1;
        }
        else {
          uVar6 = (int)local_38 % local_10;
        }
      }
      uVar5 = FUN_005fc4f0(piVar2[0xe]);
      if (uVar6 == uVar5) {
        if (((uVar6 == local_10 - 1U) && ((*(byte *)(piVar2 + 0xc) & 2) == 0)) &&
           ((piVar2[0x1c] == -1 || (iVar7 = FUN_00560f10(piVar2[0x1c]), iVar7 != 1)))) {
          piVar2[0x32] = 0;
          piVar2[0x33] = 1;
        }
      }
      else {
        piVar2[0x148] = 1;
        if ((int)uVar6 < (int)uVar5) {
          iVar7 = (local_10 - uVar5) + uVar6;
          if (piVar2[0x1a] == 0) {
            FUN_00561a00(piVar2[0x1c],1,1);
          }
        }
        else {
          iVar7 = uVar6 - uVar5;
        }
        FUN_005fb0b0(piVar2[0xe],iVar7);
        piVar2[0x28] = uVar4;
        piVar2[0x29] = local_2c;
      }
    }
    if ((code *)piVar2[0x158] != (code *)0x0) {
      (*(code *)piVar2[0x158])(piVar2,piVar2[0x159]);
      piVar2[0x34] = 1;
      return 0;
    }
  }
  return 0;
}

