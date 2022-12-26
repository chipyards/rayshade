# listes

SRCCOMMON= expr.c memory.c rotate.c sampling.c scale.c transform.c translate.c vecmath.c xform.c
SRCIMAGE= image.c
SRCLIGHT= extended.c infinite.c jittered.c light.c point.c shadow.c spot.c
SRCOBJ= blob.c bounds.c box.c cone.c csg.c cylinder.c disc.c geom.c grid.c hf.c instance.c \
        intersect.c list.c plane.c poly.c roots.c sphere.c torus.c triangle.c
SRCSURF= atmosphere.c fog.c fogdeck.c mist.c surface.c surfshade.c
SRCTEXT= blotch.c bump.c checker.c cloud.c fbm.c fbmbump.c gloss.c imagetext.c mapping.c \
         marble.c mount.c noise.c sky.c stripe.c textaux.c texture.c windy.c wood.c
SRCSHADE= bmp_.c builtin.c lex.c lightdef.c misc.c objdef.c options.c picture.c setup.c \
          shade.c stats.c surfdef.c symtab.c viewing.c y.tab.c
SRCRAY= main.c raytrace.c version.c


SOURCESC= $(SRCCOMMON) $(SRCIMAGE) $(SRCLIGHT) $(SRCOBJ) $(SRCSURF) $(SRCTEXT) $(SRCSHADE) $(SRCRAY)
SOURCESCPP=
EXE= ray.exe
OBJS= $(SOURCESC:.c=.o) $(SOURCESCPP:.cpp=.o)
     
HEADERS=  dirlist.h
  
# cibles

ALL : $(OBJS) 
	g++ -o $(EXE) $(OBJS)

clean : 
	rm *.o

.cpp.o: 
	g++ -Wall -c -O3 $<

.c.o: 
	gcc -Wall -c -O3 $<

# dependances

