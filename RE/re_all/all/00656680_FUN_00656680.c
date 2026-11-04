
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_00656680(int param_1,undefined2 *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  char *pcVar8;
  bool bVar9;
  undefined4 local_8;
  undefined4 local_4;
  
  puVar3 = param_2;
  iVar6 = param_1;
  FUN_00655bc0(param_1,*param_2,&param_1);
  if (param_1 == -1) {
    FUN_006512e0(*(undefined4 *)(iVar6 + 0x274),s_TIFFFetchNormalTag_00a0a5a0,
                 s_No_definition_found_for_tag__d_00a0a5b4,*puVar3);
    return 0;
  }
  iVar1 = *(int *)(*(int *)(iVar6 + 0x290) + param_1 * 4);
  switch(*(undefined4 *)(iVar1 + 0x10)) {
  case 1:
    iVar5 = FUN_00657e10(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    uVar2 = *(uint *)(puVar3 + 4);
    uVar4 = 0;
    if (uVar2 != 0) {
      do {
        if (*(char *)(uVar4 + (int)param_2) == '\0') break;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
    }
    if (uVar4 + 1 < uVar2) {
      FUN_00653460(*(undefined4 *)(iVar6 + 0x274),"TIFFFetchNormalTag",
                   s_ASCII_value_for_tag___s__contain_00a0a51c,*(undefined4 *)(iVar1 + 0x1c));
    }
    else if (uVar2 < uVar4 + 1) {
      FUN_00653460(*(undefined4 *)(iVar6 + 0x274),"TIFFFetchNormalTag",
                   s_ASCII_value_for_tag___s__does_no_00a0a4e8,*(undefined4 *)(iVar1 + 0x1c));
      if ((*(int *)(puVar3 + 6) + (uint)(0xfffffffe < *(uint *)(puVar3 + 4)) != 0) ||
         (puVar7 = (undefined2 *)FUN_006507d0(), puVar7 == (undefined2 *)0x0)) {
        if (param_2 == (undefined2 *)0x0) {
          return 0;
        }
        FUN_006507e0();
        return 0;
      }
      FUN_00650840(puVar7,param_2,*(undefined4 *)(puVar3 + 4));
      *(undefined1 *)((int)puVar7 + *(int *)(puVar3 + 4)) = 0;
      if (param_2 != (undefined2 *)0x0) {
        FUN_006507e0();
      }
      param_2 = puVar7;
    }
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,param_2);
    break;
  case 2:
    param_2 = (undefined2 *)((uint)param_2 & 0xffffff00);
    iVar5 = FUN_00657260(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    puVar7 = (undefined2 *)((uint)param_2 & 0xff);
    goto LAB_00656831;
  default:
    goto switchD_006566f1_caseD_3;
  case 4:
    iVar5 = FUN_00654a90(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    puVar7 = (undefined2 *)((uint)param_2 & 0xffff);
    goto LAB_00656831;
  case 6:
    iVar5 = FUN_00657470(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    puVar7 = param_2;
LAB_00656831:
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar7);
    bVar9 = iVar6 == 0;
    goto LAB_0065714d;
  case 8:
    iVar5 = FUN_00657670(iVar6,puVar3,&local_8);
    if (iVar5 != 0) goto LAB_0065715e;
    goto LAB_00656901;
  case 10:
    iVar5 = FUN_00657880(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,(double)(float)param_2);
    bVar9 = iVar6 == 0;
    goto LAB_0065714d;
  case 0xb:
    iVar5 = FUN_00657b10(iVar6,puVar3,&local_8);
    if (iVar5 != 0) goto LAB_0065715e;
LAB_00656901:
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,local_8,local_4);
    bVar9 = iVar6 == 0;
    goto LAB_0065714d;
  case 0xc:
    iVar5 = FUN_00657d70(iVar6,puVar3,&local_8);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,local_8,local_4);
    bVar9 = iVar6 == 0;
    goto LAB_0065714d;
  case 0xe:
    if ((*(int *)(puVar3 + 4) != 2) || (*(int *)(puVar3 + 6) != 0)) {
      FUN_00653460(*(undefined4 *)(iVar6 + 0x274),"TIFFFetchNormalTag",
                   s_incorrect_count_for_field___s___e_00a0a4b4,*(undefined4 *)(iVar1 + 0x1c),
                   *(undefined4 *)(puVar3 + 4));
      return 0;
    }
    iVar5 = FUN_00654cb0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*param_2,param_2[1]);
    FUN_006507e0(param_2);
    goto LAB_0065714b;
  case 0x10:
    iVar5 = (int)*(short *)(iVar1 + 4);
    if ((*(int *)(puVar3 + 4) != iVar5) || (*(int *)(puVar3 + 6) != iVar5 >> 0x1f)) {
      FUN_00653460(*(undefined4 *)(iVar6 + 0x274),"TIFFFetchNormalTag",
                   s_incorrect_count_for_field___s___e_00a0a480,*(undefined4 *)(iVar1 + 0x1c),iVar5,
                   *(undefined4 *)(puVar3 + 4));
      return 0;
    }
    iVar5 = FUN_00657e10(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,param_2);
    break;
  case 0x12:
    if (*(int *)(puVar3 + 4) != (int)*(short *)(iVar1 + 4)) {
      return 1;
    }
    if (*(int *)(puVar3 + 6) != (int)*(short *)(iVar1 + 4) >> 0x1f) {
      return 1;
    }
    iVar5 = FUN_00654cb0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,param_2);
    break;
  case 0x14:
    if (*(int *)(puVar3 + 4) != (int)*(short *)(iVar1 + 4)) {
      return 1;
    }
    if (*(int *)(puVar3 + 6) != (int)*(short *)(iVar1 + 4) >> 0x1f) {
      return 1;
    }
    iVar5 = FUN_00658920(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,param_2);
    break;
  case 0x18:
    if (*(int *)(puVar3 + 4) != (int)*(short *)(iVar1 + 4)) {
      return 1;
    }
    if (*(int *)(puVar3 + 6) != (int)*(short *)(iVar1 + 4) >> 0x1f) {
      return 1;
    }
    iVar5 = FUN_006596d0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,param_2);
    break;
  case 0x1b:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) {
LAB_00657159:
      iVar5 = 1;
LAB_0065715e:
      if (iVar1 == 0) {
        pcVar8 = s_unknown_tagname_00a09ed0;
      }
      else {
        pcVar8 = *(char **)(iVar1 + 0x1c);
      }
      FUN_00655980(iVar6,iVar5,"TIFFFetchNormalTag",pcVar8,param_3);
      return 0;
    }
    iVar5 = FUN_00657e10(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x1c:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) goto LAB_00657159;
    iVar5 = FUN_00657e10(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x1e:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) goto LAB_00657159;
    iVar5 = FUN_00654cb0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x20:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) goto LAB_00657159;
    iVar5 = FUN_00658920(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x22:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) goto LAB_00657159;
    iVar5 = FUN_00659030(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x24:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) goto LAB_00657159;
    iVar5 = FUN_006596d0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x25:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) goto LAB_00657159;
    iVar5 = FUN_006551f0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x26:
    if ((*(int *)(puVar3 + 6) != 0) || (0xffff < *(uint *)(puVar3 + 4))) goto LAB_00657159;
    iVar5 = FUN_00659b80(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,puVar3[4],param_2);
    break;
  case 0x27:
    iVar5 = FUN_00657e10(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x28:
    iVar5 = FUN_00657e10(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x29:
    param_2 = (undefined2 *)0x0;
    iVar5 = FUN_006581d0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x2a:
    iVar5 = FUN_00654cb0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x2b:
    param_2 = (undefined2 *)0x0;
    iVar5 = FUN_00658580(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x2c:
    iVar5 = FUN_00658920(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x2d:
    param_2 = (undefined2 *)0x0;
    iVar5 = FUN_00658cc0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x2e:
    iVar5 = FUN_00659030(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x2f:
    param_2 = (undefined2 *)0x0;
    iVar5 = FUN_006593c0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x30:
    iVar5 = FUN_006596d0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x31:
    iVar5 = FUN_006551f0(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
    break;
  case 0x32:
    iVar5 = FUN_00659b80(iVar6,puVar3,&param_2);
    if (iVar5 != 0) goto LAB_0065715e;
    iVar6 = FUN_0064e1d0(iVar6,*puVar3,*(undefined4 *)(puVar3 + 4),param_2);
  }
  if (param_2 != (undefined2 *)0x0) {
    FUN_006507e0();
  }
LAB_0065714b:
  bVar9 = iVar6 == 0;
LAB_0065714d:
  if (bVar9) {
    return 0;
  }
switchD_006566f1_caseD_3:
  return 1;
}

