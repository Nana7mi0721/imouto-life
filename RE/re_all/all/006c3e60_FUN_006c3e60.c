
uint FUN_006c3e60(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint local_8;
  int local_4;
  
  if (*(int *)(param_1 + 0x5c) < 2) {
    return 0xffffff7d;
  }
LAB_006c3e80:
  do {
    if (3 < *(int *)(param_1 + 0x5c)) {
      if (*(int *)(param_1 + 0x14) == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(param_1 + 0x60);
      }
      iVar3 = *(int *)(param_1 + 0x21fc);
      iVar6 = *(int *)(iVar6 * 0x160 + 0x30 + *(int *)(param_1 + 0x1c));
      uVar1 = *(int *)(param_1 + 0x2200) - iVar3;
      if (0 < (int)uVar1) {
        if (param_3 < (int)(uVar1 * iVar6)) {
          uVar1 = param_3 / iVar6;
        }
        puVar7 = (undefined4 *)(*(int *)(param_1 + 0x21f8) + iVar3 * iVar6 * 4);
        for (uVar5 = uVar1 * iVar6 & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
          *param_2 = *puVar7;
          puVar7 = puVar7 + 1;
          param_2 = param_2 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)param_2 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          param_2 = (undefined4 *)((int)param_2 + 1);
        }
        *(uint *)(param_1 + 0x21fc) = uVar1 + iVar3;
        if (param_4 == (undefined4 *)0x0) {
          return uVar1;
        }
        *param_4 = *(undefined4 *)(param_1 + 0x60);
        return uVar1;
      }
      iVar3 = *(int *)(param_1 + 0x21d0);
      if (iVar3 < *(int *)(param_1 + 0x21d4)) {
        uVar1 = *(uint *)(param_1 + 100);
        puVar7 = (undefined4 *)(iVar3 * 0x20 + 0x1f0 + param_1);
        *(int *)(param_1 + 0x21d0) = iVar3 + 1;
        uVar2 = FUN_006c0e70(*puVar7,puVar7[1]);
        uVar5 = uVar2;
        if (puVar7[3] != 0) {
          iVar3 = FUN_006c0d50(puVar7[4],puVar7[5],*(undefined4 *)(param_1 + 0x68),
                               *(undefined4 *)(param_1 + 0x6c));
          if (iVar3 < 1) {
            uVar5 = 0;
          }
          else {
            iVar3 = FUN_006c0c50(&local_8,puVar7[4],puVar7[5],*(undefined4 *)(param_1 + 0x68),
                                 *(undefined4 *)(param_1 + 0x6c));
            if ((iVar3 == 0) &&
               (((int)uVar2 >> 0x1f < local_4 ||
                ((uVar5 = local_8, (int)uVar2 >> 0x1f <= local_4 && (uVar2 <= local_8)))))) {
              uVar5 = uVar2;
            }
          }
        }
        *(undefined4 *)(param_1 + 0x68) = puVar7[4];
        *(undefined4 *)(param_1 + 0x6c) = puVar7[5];
        if (param_3 < (int)(uVar2 * iVar6)) {
          iVar3 = *(int *)(param_1 + 0x21f8);
          if (iVar3 == 0) {
            uVar4 = FUN_006c4160(param_1);
            if ((int)uVar4 < 0) {
              return uVar4;
            }
            iVar3 = *(int *)(param_1 + 0x21f8);
          }
          uVar2 = FUN_006c41d0(param_1,iVar3,puVar7,uVar2,iVar6);
          if ((int)uVar2 < 0) {
            return uVar2;
          }
          uVar2 = uVar5;
          if ((int)uVar1 <= (int)uVar5) {
            uVar2 = uVar1;
          }
          uVar4 = *(uint *)(param_1 + 0x78);
          *(uint *)(param_1 + 100) = uVar1 - uVar2;
          *(uint *)(param_1 + 0x21fc) = uVar2;
          *(uint *)(param_1 + 0x2200) = uVar5;
          uVar1 = puVar7[1];
          *(uint *)(param_1 + 0x78) = uVar4 + uVar1;
          uVar5 = uVar5 - uVar2;
          uVar2 = *(uint *)(param_1 + 0x80);
          *(uint *)(param_1 + 0x7c) =
               *(int *)(param_1 + 0x7c) + ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar4,uVar1);
          *(uint *)(param_1 + 0x80) = uVar2 + uVar5;
          *(uint *)(param_1 + 0x84) =
               *(int *)(param_1 + 0x84) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar2,uVar5);
        }
        else {
          uVar2 = FUN_006c41d0(param_1,param_2,puVar7,uVar2,iVar6);
          if ((int)uVar2 < 0) {
            return uVar2;
          }
          if (0 < (int)uVar5) {
            uVar2 = uVar5;
            if ((int)uVar1 <= (int)uVar5) {
              uVar2 = uVar1;
            }
            uVar5 = uVar5 - uVar2;
            *(uint *)(param_1 + 100) = uVar1 - uVar2;
            if ((0 < (int)uVar5) && (0 < (int)uVar2)) {
              _memmove(param_2,param_2 + uVar2 * iVar6,uVar5 * iVar6 * 4);
            }
            uVar1 = puVar7[1];
            uVar2 = *(uint *)(param_1 + 0x78);
            uVar4 = *(uint *)(param_1 + 0x80);
            *(uint *)(param_1 + 0x78) = uVar2 + uVar1;
            *(uint *)(param_1 + 0x7c) =
                 *(int *)(param_1 + 0x7c) + ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar2,uVar1);
            *(uint *)(param_1 + 0x80) = uVar4 + uVar5;
            *(uint *)(param_1 + 0x84) =
                 *(int *)(param_1 + 0x84) + ((int)uVar5 >> 0x1f) + (uint)CARRY4(uVar4,uVar5);
            if (0 < (int)uVar5) {
              if (param_4 != (undefined4 *)0x0) {
                *param_4 = *(undefined4 *)(param_1 + 0x60);
              }
              return uVar5;
            }
          }
        }
        goto LAB_006c3e80;
      }
    }
    uVar1 = FUN_006c26f0(param_1,0,0xffffffff,0xffffffff,1,1,0);
    if (uVar1 == 0xfffffffe) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = *(undefined4 *)(param_1 + 0x60);
      }
      return 0;
    }
    if ((int)uVar1 < 0) {
      return uVar1;
    }
  } while( true );
}

