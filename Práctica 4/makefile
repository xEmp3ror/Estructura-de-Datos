NAME=principal

#
OBJECTS = $(NAME).o funcionesAuxiliares.o graph.o vertex.o edge.o

#
CPPFLAGS = -c -g -Wall -ansi -O2

INCLUDES = funcionesAuxiliares.hpp graph.hpp vertex.hpp edge.hpp macros.hpp

# Macros predefinidas
#
# $@: nombre del objetivo
# $^: todas las dependencias
# $<: primera dependencia
#

objetivo: $(NAME).exe

#Opciones para NO depurar los asertos
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

# Primer objetivo 
$(NAME).exe: $(OBJECTS)
			@echo "Generando " $@
			@g++ $^ -o $@
#
$(NAME).o: $(NAME).cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
funcionesAuxiliares.o: funcionesAuxiliares.cpp $(INCLUDES)
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
vertex.o: vertex.cpp vertex.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<

#
edge.o: edge.cpp edge.hpp  vertex.hpp 
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<


#
graph.o: graph.cpp graph.hpp \
						edge.hpp \
						vertex.hpp
			@echo "Compilando " $<
			@g++ $(CPPFLAGS) $<





# Generación de la documentación
doc: Doxyfile 
	@echo "Generando la documentación con doxygen"
	@doxygen
  
# Borrado
.PHONY: clean  
clean:
	@echo "Borrando los ficheros superfluos"
	@rm -f $(OBJECTS) *~ 

